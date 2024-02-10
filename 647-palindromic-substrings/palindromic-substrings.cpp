class Solution {
public:
    bool pal(string s) {
        int n = s.length();
        int i=0,j=n-1;
        while(i != n/2){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = s.length() , c = 0;
        for(int i = 0 ; i < n ; i++ ) {
            string f = "";
            for(int j = i ; j < n ; j++ ) {
                f+=s[j];
                if(pal(f)) c++;
            }
        }

        return c;
    }
};