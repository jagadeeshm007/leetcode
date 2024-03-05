class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i =0,j=n;
        while(i<j-1){
            if(s[i]==s[j-1]){
                while(i<j-1 and s[i]==s[i+1]) i++;
                while(i<j and s[j-1]==s[j-2]) j--;
                i++;
                j--;
            }
            else{
                break;
            }
        }
        if(i>j-1) return 0;
        return j-i;
    }
};