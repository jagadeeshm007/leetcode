class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n = nums.size(),i=0,j=1;
        vector<int> result(n,0);
        for(int k = 0 ; k < n ; k++ ) {
            if(nums[k]<0){
                result[j]=nums[k];
                j+=2;
            }
            else{
                result[i]=nums[k];
                i+=2;
            }
        }

        return result;
    }
};