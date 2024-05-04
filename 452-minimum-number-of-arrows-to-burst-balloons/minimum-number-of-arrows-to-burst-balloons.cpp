class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size(), cnt = 1;
        int x = points[0][1];
        for(int i=1;i<n;i++){
            
            if(x < points[i][0]){
                cnt++;
                x = points[i][1];
            }
            else{
                x = min(x,points[i][1]);
            }
        }
        return cnt;
    }
};