class Solution {
public:
    int dp[1001][1001]; 

    int solve(int i, int j, string& text1, string& text2, int n, int m) {
        if (i == n || j == m) return 0; 

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, n, m);
        } else {
            dp[i][j] = max(
                solve(i + 1, j, text1, text2, n, m),
                solve(i, j + 1, text1, text2, n, m)
            );
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int n = text1.size();
        int m = text2.size();
        return solve(0, 0, text1, text2, n, m);
    }
};
