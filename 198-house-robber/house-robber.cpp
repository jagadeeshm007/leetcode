class Solution {
public:
    int house(vector<int> &arr ,int n, int i,vector<int> &dp){
        if(i>=n) return 0 ;
        if(dp[i]!=-1) return dp[i];
        int a = arr[i]+house(arr,n,i+2,dp);
        int b = house(arr,n,i+1,dp);
        dp[i] = max(a,b);
        return max(a,b);
    }
    int rob(vector<int>& arr) {
        vector<int> dp(arr.size(),-1);
        return house(arr,arr.size(),0,dp);
    }
};