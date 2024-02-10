class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[32]={0};

        for(auto j : nums) {
            int c=0;
            for(int i=0;i<32;i++) arr[i]+= (j & 1<<i) != 0;
        }
        int ans = 0;
        for(int i=0;i<32;i++){
            if(arr[i]%3!=0) ans |= 1<<i; 
        }
        return ans;
    }
};