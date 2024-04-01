class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        for(int i = s.length() - 1 ; i>=0 ; i--) {
            if(s[i]!=' '){
                while(i>=0) {
                    if(s[i]!=' ') c++;
                    else return c;
                    i--;
                }
            }
        }
        return c;
    }
};