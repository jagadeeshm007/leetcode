class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(),m = t.length();
        if(m<n) return false;
        if(n==m && s==t) return true;
        else if(n==m && s!=t) return false;

        for(int i=0,j=0;i<m;i++){
            if(t[i]==s[j]) j++;
            if(j==n) return true;
        }
        
        return false;
    }
};