class Solution {
public:
vector<vector<int>> dp;
    int solve(int i, vector<int>& coins, int amount) {
        // base conditions
        if (amount == 0) return 0;
        if (i >= coins.size() || amount < 0) return 1e9;
  if (dp[i][amount] != -1) return dp[i][amount];
        // take (reuse same coin)
        int take = 1e9;
        if (amount >= coins[i]) {
            take = 1 + solve(i, coins, amount - coins[i]);
        }

        // not take (move to next coin)
        int notake = solve(i + 1, coins, amount);

return dp[i][amount] = min(take, notake);
    }

   int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    dp.assign(coins.size(), vector<int>(amount + 1, -1));
    int ans = solve(0, coins, amount);
    return (ans >= 1e9) ? -1 : ans;
}

};
