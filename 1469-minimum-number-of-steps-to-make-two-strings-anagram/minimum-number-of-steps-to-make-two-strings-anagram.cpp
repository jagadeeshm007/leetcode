class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> vs(26,0);
        vector<int> vt(26,0);
        for(int i=0; i < s.length() ; i++ ) {
            vs[s[i]-'a']++;
            vt[t[i]-'a']++;
        }
        int ans = 0 , res1 = 0, res2 = 0;
        for(int i = 0 ; i < 26 ; i++) {
            int sub = min(vs[i],vt[i]);
            res1 += (vs[i] - sub);
            res2 += (vt[i] - sub);
        }

        return max(res1,res2);
    }
};