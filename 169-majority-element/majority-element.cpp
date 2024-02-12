class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for( int i = 0 ; i < n ; i ++ ) {
            mp[nums[i]]++;
        }
        int mx=0,cnt=0;
        for(auto i : mp) {
            if(i.second>=cnt) {
                cnt=i.second;
                mx=i.first;
            }
        }

        return mx;
    }
};