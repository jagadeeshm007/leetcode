class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> v(10, vector<int>(10, 0));
        long long ans=0;

        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i],j=0;
            while(tmp){
                v[j++][tmp%10]++;
                tmp/=10;
            }
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    if(j!=k) ans+= v[i][j]*v[i][k];
                }
            }
            
        }

        return ans/2;
    }
};