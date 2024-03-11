class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26,0);
        string ans="";
        for(auto it:s){
            v[it-'a']++;
        }
        for(auto it:order) {
            if(v[it-'a']) {
                ans+= string(v[it-'a'], it);
                v[it-'a']=0;
            }
        }
        for(int i=0;i<26;i++) {
            if(v[i]){
                char c = i+'a';
                ans+= string(v[i], c);
            }
        }
        return ans;
    }
};