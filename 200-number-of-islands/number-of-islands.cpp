class Solution {
public:
    void marker(int i,int j,vector<vector<char>>& grid,int mrk){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!= '1') return;
        grid[i][j] = '0';
        marker(i+1,j,grid,mrk);
        marker(i-1,j,grid,mrk);
        marker(i,j+1,grid,mrk);
        marker(i,j-1,grid,mrk);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mrk=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1'){
                    marker(i,j,grid,mrk);
                    mrk++;
                }
            }
        }

        return mrk;
    }
};