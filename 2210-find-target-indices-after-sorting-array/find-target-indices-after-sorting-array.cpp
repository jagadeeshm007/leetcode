class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> c;
        if(binary_search(nums.begin(),nums.end(),target)){
        int k= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        for(int i=k;i<nums.size();i++) {
            if(nums[i]==target) c.push_back(i);
        }
        }
        else return {};

        return c;
    }
};