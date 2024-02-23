class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() , j=1;
        for(int i = 1 ; i < n ; i++ ) {
            if(nums[i-1]!=nums[i]){
                nums[j] = nums[i];
                j++;
            }
        }
        for(int i = j ; i < n ; i ++){
            nums.pop_back();
        }
        return nums.size();
    }
};