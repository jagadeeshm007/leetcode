class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto i:edges){
            for(auto j:i) mp[j]++;
        }
        int mx=0,ans=0;
        for(auto i: mp){
            if(i.second>mx){
                mx=i.second;
                ans=i.first;
            }
        }

        return ans;
    }
};