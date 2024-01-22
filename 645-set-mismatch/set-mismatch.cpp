class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n+1,0);
        int b = 0,c=0,v=0;
        for(int i = 1 ; i <= n ; i++ ) { 
            if(a[nums[i-1]]==1) v=nums[i-1];
            b^=nums[i-1];
            c^=i;
            a[nums[i-1]]++;
        }
        return {v,(b^c^v)};
    }
};