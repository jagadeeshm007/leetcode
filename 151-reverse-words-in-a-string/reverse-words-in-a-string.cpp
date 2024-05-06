class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int n = s.length();
        int i=0,j=0,k=0;
        while(i<n) {
            while(i<n && s[i]==' ') i++;
            if(i==n) break;
            while(i<n && s[i]!=' ') s[j++] = s[i++];
            reverse(s.begin()+k,s.begin()+j);
            s[j++]=' ';
            k=j;
            i++;
        }

        s.resize(j-1); //new : resize the string to given length

        return s;
    }
};