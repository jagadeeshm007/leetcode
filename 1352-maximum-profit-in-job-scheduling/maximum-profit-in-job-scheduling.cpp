class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& e, vector<int>& p) {
        int n = st.size(); 
        vector<pair<int, int>> v(n);
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; i++) v[i] = {st[i], i};
        sort(v.begin(), v.end());
        for(int i=n-1;i>-1;i--)
        {
            pair<int, int> pr = make_pair(e[v[i].second], 0);
            int x = lower_bound(v.begin() + i, v.end(), pr) - v.begin();
            dp[i] += max(dp[i+1], p[v[i].second] + dp[x]);
        }
        return dp[0];
    }
};