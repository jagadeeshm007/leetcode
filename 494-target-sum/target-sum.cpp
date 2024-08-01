class Solution {
public:
    unordered_map<string,int> dp;
    int solve(int i,int sum,vector<int>& nums, int target) {
        if(i>=nums.size()){
            if(sum == target) return 1;
            else return 0;
        }
        string key = to_string(i)+"-"+to_string(sum);
        if(dp.count(key)) return dp[key];
        return dp[key] = solve(i+1,sum-nums[i],nums,target) + solve(i+1,sum+nums[i],nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};