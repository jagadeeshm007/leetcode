class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        return (n*(n+1))/2 - accumulate(nums.begin(),nums.end(),0);
    }
};
