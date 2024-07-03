class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 5) return 0;
        sort(begin(nums),end(nums));
        int case0 = nums[n-4] - nums[0];
        int case1 = nums[n-3] - nums[1];
        int case2 = nums[n-2] - nums[2];
        int case3 = nums[n-1] - nums[3];
        return min({case0,case1,case2,case3});
    }
};