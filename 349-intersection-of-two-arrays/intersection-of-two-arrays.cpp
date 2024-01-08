class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        set<int> v;
        for(auto i : nums1) mp[i]++;
        for(auto i : nums2) {
            if(mp.count(i)) v.insert(i);
        }
        vector<int> a(v.begin(),v.end());
        return a;
    }
};