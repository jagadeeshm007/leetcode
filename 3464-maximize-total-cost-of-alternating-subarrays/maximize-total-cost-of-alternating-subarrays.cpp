class Solution {
public:
    long long dp[100001][2];
    long long solve(int i,int flg,int n,vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i][flg]!=-1) return dp[i][flg];
        long long p=INT_MIN,np=INT_MIN;
        if(flg){
            p = abs(nums[i])+solve(i+1,0,n,nums);
        }
        np= nums[i]+solve(i+1,1,n,nums);
        return dp[i][flg] = max(p,np);
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums[0];
        memset(dp,-1,sizeof(dp));
        return nums[0]+solve(1,1,n,nums);
    }
};