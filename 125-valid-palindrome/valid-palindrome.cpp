class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (isalnum(s[i])) {
                res += (islower(s[i]) ? s[i] : tolower(s[i]));
            }
        }
        int length = res.length();
        for(int i=0,j=length-1;i<length;i++,j--) if(res[i]!=res[j]) return false;
        
        return true;
    }
};