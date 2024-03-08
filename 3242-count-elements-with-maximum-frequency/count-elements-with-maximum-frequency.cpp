class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,mxfrq = 0;
        vector<int> frq(101,0);
        for(int i = 0 ; i < n ; i++ ) {
            frq[nums[i]]++;
        }
        for(int i = 0 ; i < 101 ; i++ ){
            mxfrq = max(mxfrq,frq[i]);
        }
        for(int i = 0 ; i < 101 ; i++ ){
            ans += (frq[i] == mxfrq);
        }
        return ans*mxfrq;
    }
};