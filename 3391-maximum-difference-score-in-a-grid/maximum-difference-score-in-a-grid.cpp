class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int m = INT_MAX;
                if(i==0 && j==0) continue;
                if(i!=0) m = min(m, grid[i-1][j]);
                if(j!=0) m = min(m, grid[i][j-1]);
                ans = max(ans,grid[i][j] - m);
                grid[i][j] = min(grid[i][j],m);
            }
        }
        
        return ans;
    }
};