class Solution {
public:
    int dp[21][2003];
    int solve(int i,int sum,vector<int>& nums, int target) {
        if(i>=nums.size()){
            if(sum == target) return 1;
            else return 0;
        }
        if(dp[i][sum+1000] != -1 ) return dp[i][sum+1000];
        return dp[i][sum+1000] = solve(i+1,sum-nums[i],nums,target) + solve(i+1,sum+nums[i],nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums,target);
    }
};