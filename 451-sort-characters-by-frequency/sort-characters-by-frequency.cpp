class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        map<int,vector<string>> fq;
        for(auto i : s) mp[i]++;
        string result="";
        for(auto i : mp) {
            string c(i.second,i.first);
            fq[i.second].push_back(c);
        }
        for(auto i : fq){
            for(auto j : i.second){
                result=j+result;
            }
        }
        return result;
    }
};