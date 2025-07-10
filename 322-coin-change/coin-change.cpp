class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0 || i >= coins.size()) return 1e9; // use large value to indicate impossible

        if (dp[i][amount] != -1) return dp[i][amount];

        // take the coin
        int take = 1 + solve(i, coins, amount - coins[i]);

        // skip the coin
        int skip = solve(i + 1, coins, amount);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>>(n + 1, vector<int>(amount + 1, -1));
        int res = solve(0, coins, amount);
        return (res >= 1e9) ? -1 : res;
    }
};
