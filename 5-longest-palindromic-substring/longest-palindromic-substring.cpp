#define SIZE 100000 + 1
int p[SIZE * 2];

class Solution {
public:
    string convert(string s) {
        string newString = "@";
        for (int i = 0; i < s.size(); i++)
            newString += "#" + s.substr(i, 1);
        newString += "#$";
        return newString;
    }
    string longestPalindrome(string s) {
        string cp = s;
        s = convert(s);
        int n = s.size()-2;
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        int mx=-1,it=-1;
        for(int i=0;i<n;i++) {
            if(mx<p[i]){
                mx=p[i];
                it=i;
            }
        }
        string q;
        for(int i=it-mx+1;i<it+mx;i++){
            if(s[i]!='#') q+=s[i];
        }

        return q;
    }
};