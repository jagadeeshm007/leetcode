class Solution {
public:
    long long minmin(vector<vector<int>>& triangle, int n, int j,vector<vector<int>> &dp) {
        
        if (n <= 0) {
            return  triangle[0][0];
        }
        if(dp[n][j]!=INT_MAX){
            return dp[n][j];
        }
        long long p = 1e5, q = 1e5;
        int m = triangle[n].size();
        if (j>0) {
            p = min( p , triangle[n][j] + minmin(triangle, n - 1, j - 1,dp));
        }
        if (j<m-1) {
            q = min(q , triangle[n][j] + minmin(triangle, n - 1, j,dp));
        }
        return  dp[n][j] = min(p, q);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        long long p = 1e5, q = 1e5;
        int n = triangle.size() - 1;
        int m = triangle[n].size() ;
        if(n==0 and m==1) return triangle[0][0];
        vector<vector<int>> dp(n+2,vector<int>(m+1,INT_MAX));
        
        for (int j = 0; j < m; j++) {
            if (j>0) {
                p = min(p,triangle[n][j] + minmin(triangle, n - 1, j - 1,dp));
            }
            if (j<m-1) {
                q = min(q,triangle[n][j] + minmin(triangle, n - 1, j,dp));
            }
        }
        cout<<p<<" "<<q<<endl;
        return min(p, q);
    }
};