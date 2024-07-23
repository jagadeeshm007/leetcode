class Solution {
public:
    int dp[10000];
    int find(vector<int>& nums,int i,int n){
        if(i>=n)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int p=0;
        for(int j=i+1;j<=i+nums[i];j++){
            if(j<=n) p = max(p,find(nums,j,n));
           if(p) break;
        }
        return dp[i]=p;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return find(nums,0,n-1);
    }
};