class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length(),c=0;
        string str = "aeiouAEIOU";
        for(int i=0,j=n-1 ; i < n/2 ; i++,j--){
            if (str.find(s[i]) != string::npos) c++;
            if (str.find(s[j]) != string::npos) c--;
        }
        return (c==0);
    }
};