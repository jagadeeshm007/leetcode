class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int result = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1;
            int k = n-1 ;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                        j++;
                        continue; 
                    }
                    if (k < nums.size() - 1 && nums[k] == nums[k + 1]) {
                        k--;
                        continue; 
                    }
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans)) {
                    ans = sum - target;  
                    result = sum;
                }
                if (sum > target) {
                    k--;  
                } 
                else {
                    j++; 
                }
            }
        }
        return result;
    }
};