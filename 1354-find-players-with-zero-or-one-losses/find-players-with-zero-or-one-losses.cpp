class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> mp;
        for(int i=0 ; i<matches.size() ; i++) {
            mp[matches[i][0]].first ++;
            mp[matches[i][1]].second ++;
        }
        vector<int> zero_lost,one_lost;
        for(auto i : mp){
            auto j = i.second;
            if(j.first > 0 && j.second == 0) zero_lost.push_back(i.first);
            if(j.second ==1) one_lost.push_back(i.first);
        }
        return {zero_lost,one_lost};
    }
};