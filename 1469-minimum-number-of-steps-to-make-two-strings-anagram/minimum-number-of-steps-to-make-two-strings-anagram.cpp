class Solution {
public:
    int minSteps(string s, string t) {
        int vs[26] ={0} , ans = 0;
        for(int i = 0; i < s.length() ; i++ ) vs[s[i]-'a']++ , vs[t[i]-'a']--;
        for(int i = 0 ; i < 26 ; i++) ans += abs(vs[i]);
        return ans/2;
    }
};