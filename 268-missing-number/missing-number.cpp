class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return (n*(n+1))/2 - accumulate(nums.begin(),nums.end(),0);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();