class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), end = nums.size() - 1;
        for (int i = 0; i < n; i++) {
            if (i > end){
                break;
            }
            if (nums[i] == val) {
                while (end>=0 and nums[end] == val)
                    end--;
                if (i > end)
                    break;
                nums[i] = nums[end];
                end--;
            }
        }
        return end+1;
    }
};