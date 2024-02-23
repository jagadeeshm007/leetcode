class Solution {
public:
    int dp[101][101];
    int dfs(vector<vector<int>> adj[], int i, int j, int k) {
        if (k < 0) return 1e5;
        if (i == j) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int ans = 1e5;
        for (auto it : adj[i]) ans = min(ans, it[1] + dfs(adj, it[0], j, k - 1));
        return dp[i][k] = ans;
    }
    int findCheapestPrice(int n,vector<vector<int>>& flights, int src, int dst,int k) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> adj[n];
        vector<int> vis(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        int s = dfs(adj, src, dst, k + 1);
        return (s==1e5)?-1:s;
    }
};