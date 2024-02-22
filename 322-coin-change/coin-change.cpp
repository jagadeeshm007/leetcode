class Solution {
public:
    int dp[13][10001];
    int richboy(vector<int>& coins, int amount, int i) {
        if (amount == 0)
            return 0;
        if (amount < 0 or i >= coins.size())
            return 1e9;
        if (dp[i][amount] != -1)
            return dp[i][amount];

        int p = 1e9, q = 1e9;
        if (amount - coins[i] >= 0)
            p = 1 + richboy(coins, amount - coins[i], i);
        q = richboy(coins, amount, i + 1);

        return dp[i][amount] = min(p, q);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int s = richboy(coins, amount, 0);
        return (s == 1e9) ? -1 : s;
    }
};