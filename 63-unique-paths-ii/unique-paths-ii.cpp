class Solution {
public:
    int path(vector<vector<int>>& obstacleGrid,int i,int j,int n,int m,vector<vector<int>>& dp) {
        if(i>=n-1 && j>=m-1 && obstacleGrid[i][j] == 0) 
            return 1;
            
        if(obstacleGrid[i][j] == 1) 
            return 0;

        if(dp[i][j]!=-1) 
            return dp[i][j];

        int p=0,q=0;
        if(i+1<n && obstacleGrid[i+1][j] == 0) 
            p = path(obstacleGrid,i+1,j,n,m,dp);

        if(j+1<m && obstacleGrid[i][j+1] == 0) 
            q = path(obstacleGrid,i,j+1,n,m,dp);
        
        return dp[i][j] = p+q;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return path(obstacleGrid,0,0,n,m,dp);
    }
};