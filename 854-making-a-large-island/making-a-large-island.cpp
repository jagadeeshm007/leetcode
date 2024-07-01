class Solution {
public:
    int c=0;
    void marker(int i,int j,vector<vector<int>>& grid,int mrk){
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || grid[i][j]!=1) return;

        grid[i][j] = 0;
        c++;
        marker(i+1,j,grid,mrk);
        marker(i-1,j,grid,mrk);
        marker(i,j+1,grid,mrk);
        marker(i,j-1,grid,mrk);
        grid[i][j] = mrk;
    }
    int largestIsland(vector<vector<int>>& grid) {
        map<int,int> grp;
        grp[0]=0;
        int n = grid.size();
        int mrk=2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1){
                    c=0;
                    marker(i,j,grid,mrk);
                    grp[mrk] = c;
                    mrk++;
                }
            }
        }
        // Base cases
        if(grp.size()==1) return 1;
        if(grp.size()==2){
            if(grp[2]==(n*n)) return grp[2];
            return grp[2]+1;
        }
        // Result computimg 
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int tmp=1;
                unordered_set<int> s;
                if(grid[i][j] == 0){
                    if(i-1>=0) s.insert(grid[i-1][j]);
                    if(i+1<n) s.insert(grid[i+1][j]);
                    if(j-1>=0) s.insert(grid[i][j-1]);
                    if(j+1<n) s.insert(grid[i][j+1]);
                    for(auto it : s) tmp+=grp[it];
                }
                ans = max(ans,tmp);
            }
        }
        return ans;
    }
};