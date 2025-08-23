
class Solution {
public:
    // Approach 1: Cleaner DP with memoization
    int n;
    vector<vector<int>> dp;
    
    int solve(int i, int lastWasOne, string &s) {
        if (i == n) return 0;
        
        if (dp[i][lastWasOne] != -1) return dp[i][lastWasOne];
        
        int result = INT_MAX;
        
        // Option 1: Make current position 0
        if (!lastWasOne) { // Can place 0 only if last wasn't 1
            int cost = (s[i] == '0') ? 0 : 1; // Cost to make it 0
            result = min(result, cost + solve(i + 1, 0, s));
        }
        
        // Option 2: Make current position 1 (always allowed)
        int cost = (s[i] == '1') ? 0 : 1; // Cost to make it 1
        result = min(result, cost + solve(i + 1, 1, s));
        
        return dp[i][lastWasOne] = result;
    }
    
    int minFlipsMonoIncr(string s) {
        n = s.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(0, 0, s); // Start with lastWasOne = 0 (can place either 0 or 1)
    }
};