class NumArray {
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n,0);
        buildTree(0,n-1,0,nums);
    }
    int sumRange(int left, int right) {
        return query(left,right,0,n-1,0);
    }

private:
    vector<int> seg;
    int n;
    void buildTree(int left,int right,int idx,vector<int>& nums) {
        if(left == right) {
            seg[idx] = nums[left];
            return;
        }
        int mid = left + (right - left)/2;
        buildTree(left,mid,idx*2+1,nums);
        buildTree(mid+1,right,idx*2+2,nums);
        seg[idx] = seg[idx*2+1] + seg[idx*2+2];
    }
    int query(int left, int right,int start,int end,int idx){
        // Completely within the query range
        if(start>=left && right>=end) return seg[idx];
        // Completely out of the query range
        if(left>end || start>right ) return 0;
        // Partially within the query range
        int mid = start + (end - start)/2;
        return query(left,right,start,mid,idx*2+1) + query(left,right,mid+1,end,idx*2+2);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */