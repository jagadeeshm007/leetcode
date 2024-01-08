class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c=0,pt=grid[0].size()-1,ans=0,j=0;
        for(int i=0 ; i<grid.size() ; i++){
            if(pt==-1){
                ans+=c;
            }
            else{
                for( j=pt;j>=0;j--){
                    if(grid[i][j]<0) c++;
                    else break;
                }
                pt=j;
                ans+=c;
            }
            //cout<<i<<" "<<pt<<" "<<ans<<" "<<c<<"\n";
        }
        return ans;
    }
};