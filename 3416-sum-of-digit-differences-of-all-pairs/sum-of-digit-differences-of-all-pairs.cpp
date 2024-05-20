class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int arr[10][10];
        long long n = nums.size(),ans=0;
        for(int i=0;i<n;i++) {
            int num = nums[i], j=0;
            while(num){
                arr[j++][num%10]++;
                num/=10;
            }
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    if (j != k) ans+= (arr[i][j] * arr[i][k]);
                }
            }
        }

        return ans/2;
    }
};