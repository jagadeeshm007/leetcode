class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        
        for (int j = n-2;j>=0;j--) {
            int m = triangle[j].size();
            for(int i=0;i<m;i++){
                triangle[j][i]+=min(triangle[j+1][i],triangle[j+1][i+1]);
            }
        }
        return triangle[0][0];
    }
};