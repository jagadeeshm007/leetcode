class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //sorting of string makes lexi sort ;
        int n = strs.size();
        string ans;
        sort(strs.begin(),strs.end());
        string s1=strs[0],s2=strs[n-1];
        for(int i = 0 ; i< min(s1.length(),s2.length()) ; i++) {
            if(s1[i]==s2[i]) ans+=s1[i];
            else return ans;
        }
        return ans;
    }
};