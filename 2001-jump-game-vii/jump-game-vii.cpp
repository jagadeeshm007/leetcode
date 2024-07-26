class Solution {
public:
    int dp[100001];
    bool solve(int i, string &s, int mi, int mx){
        if(i >= s.length() || s[i] == '1') return false;
        if(i == s.length() - 1) return true;
        if(dp[i]!=-1) return dp[i];
        dp[i] = false;
        for(int j = mi;j<=mx;j++){
            if(solve(i + j, s, mi, mx)) return dp[i] = true;
        }
        return dp[i];
    }
    bool canReach(string s, int miump, int mxump) {
        if(s[s.length()-1]!='0') return false;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                cnt++;
                if(cnt >= mxump) return false;
            }
            else{
                cnt = 0;
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0, s, miump, mxump);
    }
};