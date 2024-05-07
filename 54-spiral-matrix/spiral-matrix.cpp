#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left=0,top=0,down=n-1,right=m-1;
        vector<int> ans;
        while(left<=right && top<=down){
            for(int i=left;i<=right;i++){
                ans.pb(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=down;i++){
                ans.pb(matrix[i][right]);
            }
            right--;
            if(top<=down){
                for(int i=right; i>=left;i--){
                    ans.pb(matrix[down][i]);
                }
                down--;
            }
            if(left<=right){
                for(int i=down;i>=top;i--){
                    ans.pb(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};