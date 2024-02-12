class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int> v;
        map<int,int> mp;
        for(auto i : nums ){
            mp[i]++;
            if(mp[i]>nums.size()/3) v.insert(i);
        }
        vector s(v.begin(),v.end());
        return s;
    }
};