class NumArray {
public:
    vector<long long> seg;
    int n;
    void buildTree(vector<int>& nums,int idx,int left,int right) {
        if(left == right){
            seg[idx] = nums[left];
            return;
        }
        int mid = left + (right - left)/2;
        buildTree(nums,idx*2+1,left,mid);
        buildTree(nums,idx*2+2,mid+1,right);
        seg[idx] = seg[idx*2+1] + seg[idx*2+2];
    }
    void updateSeg(int left,int right,int idx,int index,int val) {
        if(left > index || index > right) return;
        if(left == right && left==index){
            seg[idx] = val;
            return;
        }
        int mid = left+(right-left)/2;
        updateSeg(left,mid,idx*2+1,index,val);
        updateSeg(mid+1,right,idx*2+2,index,val);

        seg[idx] = seg[idx*2+1] + seg[idx*2+2];
    }
    long long query(int left,int right,int start,int end,int idx) {
        if(left > end || right < start) return 0;

        if(left<=start && right>=end) return seg[idx];

        int mid = start+(end-start)/2;
        long long p = query(left,right,start,mid,idx*2+1);
        long long q = query(left,right,mid+1,end,idx*2+2);
        return p+q;
    }
    
    NumArray(vector<int>& nums) {
        if(nums.size() > 0){
            n = nums.size();
            seg.resize(4*(n),0);
            buildTree(nums, 0, 0, n-1);
        }
    }
    
    void update(int index, int val) {
        if(n==0) return;
        updateSeg(0,n-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        if(n==0) return 0;
        return query(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */