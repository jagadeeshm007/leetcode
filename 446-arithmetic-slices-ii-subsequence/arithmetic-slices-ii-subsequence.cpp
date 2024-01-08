class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<int,int>> v(n);
        int result=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long c = 1LL*(nums[i]) - 1LL*(nums[j]);
                int val = (int)c , x = 0, y = 0;

                if(c>=INT_MAX or c<=INT_MIN) continue; 
                if(v[j].find(val) != v[j].end()){
                    x = v[i][val];
                    y = v[j][val];
                    v[i][val]=(x+y+1);
                    result+=y;
                }
                else {
                    v[i][val]++;
                }
            }
        }

        return result;
    }
};