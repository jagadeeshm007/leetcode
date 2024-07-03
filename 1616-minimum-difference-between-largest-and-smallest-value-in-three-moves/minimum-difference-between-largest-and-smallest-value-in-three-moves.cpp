class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 5) return 0;
        sort(begin(nums),end(nums));
        int case0 = abs(nums[0]-nums[n-4]);
        int case1 = abs(nums[1]-nums[n-3]);
        int case2 = abs(nums[2]-nums[n-2]);
        int case3 = abs(nums[3]-nums[n-1]);
        return min({case0,case1,case2,case3});
    }
};