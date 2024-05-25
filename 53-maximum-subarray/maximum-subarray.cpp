class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int glb_max = INT_MIN,j=0,sm=0;

        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            if(glb_max < sm) glb_max = sm;
            if(sm < 0) sm=0;
        }
        
        return glb_max;
    }
};