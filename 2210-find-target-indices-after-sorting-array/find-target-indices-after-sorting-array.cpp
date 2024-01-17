class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> c;
        int k= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(k!=nums.size() && nums[k]==target){
        for(int i=k;i<nums.size();i++) {
            if(nums[i]==target) c.push_back(i);
            else break;
        }
        }
        else return {};

        return c;
    }
};