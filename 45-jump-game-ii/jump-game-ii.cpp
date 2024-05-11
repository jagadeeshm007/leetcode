class Solution {
public:
    int find(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i>=n)
            return 0;
        if(dp[i] != -1) return dp[i];
        int p=10001;
        for(int j=i+1;j<=min(n,i+nums[i]);j++){
            int v= 1+find(nums,j,n,dp);
            p=min(p,v);
        }
        return dp[i]=p;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return find(nums,0,n-1,dp);
    }
};