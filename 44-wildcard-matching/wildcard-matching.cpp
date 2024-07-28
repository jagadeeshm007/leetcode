class Solution {
public:
    int dp[2001][2001];
    bool solve(int i,int j,string& s,string& p){
        if(j>=p.length())
            return i == s.length();
        if(i>=s.length())
            return (p[j]=='*') and solve(i,j+1,s,p);
        if(dp[i][j] != -1)
            return dp[i][j];

        bool pc = false;
        if(s[i] == p[j] || p[j]=='?') 
            pc = solve(i+1,j+1,s,p);
        else if(p[j] == '*')
            pc = solve(i+1,j,s,p) | solve(i+1,j+1,s,p) | solve(i,j+1,s,p);

        return dp[i][j] = pc;
        
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p);
    }
};