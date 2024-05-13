class Solution {
public:
    int dp[201][201][201];
    int solve(string& s1,string& s2,string& s3,int i,int j,int k){
        if(k>=s3.size())
            return 1;
            
        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        int p=0,q=0;
        if(i<s1.size() && s1[i]==s3[k])
            p = solve(s1,s2,s3,i+1,j,k+1);
        if(j<s2.size() && s2[j]==s3[k])
            q = solve(s1,s2,s3,i,j+1,k+1);
        
        return dp[i][j][k] = p|q;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        string s="";
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,0,0,0);
    }
};