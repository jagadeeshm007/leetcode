class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int s=0;
        for(int i=1;i<nums.size();i++){
           for(int j=i;j<nums.size();j++){
               if(nums[i-1]+nums[j] < target) s++;
               else break;
           }
        }
        return s;
    }
};