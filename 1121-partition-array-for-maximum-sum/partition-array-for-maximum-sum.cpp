class Solution {
public:
     int dp[501];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<arr.size()+1;i++){
            int mx=0,h=min(k,i),j=1;
            while(j<=h){
                mx=max(mx,arr[i-j]);
                dp[i]=max(dp[i],dp[i-j]+(mx*j));
                j++;
            }
        }
        return dp[arr.size()];
    }
};