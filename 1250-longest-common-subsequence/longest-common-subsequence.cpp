class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() , m = text2.length();
        vector<int> v(n+1,0);
        vector<int> pre(n+1,0);
        for(int i = 1; i<= m ; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[j-1]==text2[i-1]) v[j]=1+pre[j-1];
                else v[j] = max(pre[j],v[j-1]);
            }
            pre=v;
        }
        return v[n];
    }
};