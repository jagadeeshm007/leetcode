class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++) {
            for(int j=0;j<n;j++){
                if(i!=0 and j!=0){
                    dp[j]=dp[j-1]+dp[j];
                }
            }
        }
        return dp[n-1];
    }
};