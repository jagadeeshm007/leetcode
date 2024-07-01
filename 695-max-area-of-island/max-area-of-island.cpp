class Solution {
public:
    int c=0;
    void marker(int i,int j,vector<vector<int>>& grid,int mrk){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return;

        grid[i][j] = 0;
        c++;
        marker(i+1,j,grid,mrk);
        marker(i-1,j,grid,mrk);
        marker(i,j+1,grid,mrk);
        marker(i,j-1,grid,mrk);
        grid[i][j] = mrk;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        map<int,int> grp;
        grp[0]=0;
        int n = grid.size();
        int m = grid[0].size();
        int mrk=2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1){
                    c=0;
                    marker(i,j,grid,mrk);
                    grp[mrk] = c;
                    mrk++;
                }
            }
        }
        int ans=0;
        for(auto it : grp){
            ans=max(ans,it.second);
        }

        return ans;
    }
};