class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length() , m = needle.length();
        if(m>n) return -1;
        string check;
        for(int i=0;i<m;i++) check+=haystack[i];

        for(int i=0;i<n-m+1;i++) {
            if(check==needle) return i;
            check.erase(0,1);
            check+=haystack[m+i];
        }
        return -1;
    }
};