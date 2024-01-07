class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int b = binary_search(nums.begin(),nums.end(),target);
        if(b){
            int k = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int p = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            //if(nums[p-1]==target) return {k,p-1};
            return {k,p-1};
        }
        return {-1,-1};
    }
};