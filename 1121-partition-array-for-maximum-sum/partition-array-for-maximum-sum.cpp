class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n+1],mx = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++ ) {
            mx=0;
            for (int j = 1;j <= min(k, i); j++ ) {
                mx = max(mx, arr[i - j]);
                dp[i] = max( dp[i] , dp[i - j] + mx * j);
            }
        }

        return dp[n];
    }
};