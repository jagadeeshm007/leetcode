class Solution {
public:
    vector<long long> dp;
    long long solve(int i, vector<vector<int>>& rides){
        if(i>=rides.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int idx = lower_bound(rides.begin(),rides.end(),vector<int>{rides[i][1],0,0}) - rides.begin();
        int pr = rides[i][1] - rides[i][0] + rides[i][2];
        return dp[i] = max(solve(i+1,rides) , pr + solve(idx,rides));
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        dp.resize(rides.size()+1,-1);
        return solve(0,rides);
    }
};