class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1, c = 0;
        for(i ; i>=0 ; i--) {
            if(s[i]!=' ')break;
        }
        for(i ; i>=0 ; i--) {
            if(s[i]!=' ') {
                c++;
            }
            else {
                return c;
            }
        }
        return c;
    }
};