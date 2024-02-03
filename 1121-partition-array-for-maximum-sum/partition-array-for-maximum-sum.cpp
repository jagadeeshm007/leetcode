class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n+1],tmp=0;
        memset(dp, 0, sizeof(dp));
        for(int i = n-1; i >= 0; i--){
            int mx = arr[i] , m = min( i+k , n),j=i;
            while( j < m ) {
                mx = max(mx, arr[j]) ;
                tmp = max( tmp , (j - i + 1) * mx + dp[j+1]);
                j++;
            }
            dp[i] = tmp;
        }

        return tmp;
    }
};