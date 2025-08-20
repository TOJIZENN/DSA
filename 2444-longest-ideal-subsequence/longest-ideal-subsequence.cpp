class Solution {
public:
    int n;
    int dp[100005][27]; // [index][prev_char+1] where prev_char ranges from -1 to 25
    
    int solve(int i, string &s, int k, int prev) {
        if (i == n) return 0;
        
        // Memoization check
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        
        // Option 1: skip current character
        int notpick = solve(i + 1, s, k, prev);
        
        // Option 2: pick current character
        int curr = s[i] - 'a'; // Convert to 0-25 range
        int pick = 0;
        if (prev == -1 || abs(prev - curr) <= k) {
            pick = 1 + solve(i + 1, s, k, curr);
        }
        
        // Store result in dp table
        return dp[i][prev + 1] = max(pick, notpick);
    }
    
    int longestIdealString(string s, int k) {
        if (s.size() == 1) { return 1; }
        n = s.size();
        
        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));
        
        return solve(0, s, k, -1);
    }
};