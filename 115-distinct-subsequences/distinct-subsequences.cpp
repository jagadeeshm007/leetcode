class Solution {
public:
    long long mod = 1e9+7;
    long long dp[1001][1001];
    int mia(int i,string &s,string &t,int m) {
        if(m>=t.size()) return 1;
        if(dp[i][m]!=-1) return dp[i][m];
        if(i>=s.size()) return 0;

        long long n=0;

        n = (n % mod + mia(i+1,s,t,m) % mod) % mod;
        if(s[i] == t[m]) n = ( n % mod + mia(i+1,s,t,m+1) % mod) % mod;        
        return dp[i][m] =( n % mod);
    }
    int numDistinct(string s, string t) {
       memset(dp,-1,sizeof(dp));
      return mia(0,s,t,0);
    }
    
};