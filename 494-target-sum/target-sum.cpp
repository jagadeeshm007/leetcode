class Solution {
public:
    int solve(int i,vector<int>& nums, int target) {
        if(i<0){
            if(target==0) return 1;
            else return 0;
        }
        return solve(i-1,nums,target-nums[i]) + solve(i-1,nums,target+nums[i]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size()-1,nums,target);
    }
};