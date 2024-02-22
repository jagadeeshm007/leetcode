class Solution {
public:
    int dp[301][5001];
    int richboy(vector<int>& coins, int amount, int i) {
        if (amount == 0)
            return 1;
        if (amount < 0 or i >= coins.size())
            return 0;
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int p = 0, q = 0;
        if (amount - coins[i] >= 0)
            p = richboy(coins, amount - coins[i], i);
        q = richboy(coins, amount, i + 1);

        return dp[i][amount] = (p + q);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return richboy(coins, amount, 0);
    }
};