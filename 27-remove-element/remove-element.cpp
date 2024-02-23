class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), end = nums.size() - 1;
        for (int i = 0; i < n; i++) {
            if (i >= end)
                break;
            if (nums[i] == val) {
                while (end>=0 and nums[end] == val)
                    end--;
                if (i >= end)
                    break;
                nums[i] = nums[end];
                nums[end] = val;
                end--;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == val)
                nums.pop_back();
            else
                break;
        }

        return nums.size();
    }
};