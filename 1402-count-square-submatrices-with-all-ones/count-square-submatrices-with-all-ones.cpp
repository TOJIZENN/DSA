class Solution {
public:
   vector<vector<int>> dp;
    int ans;
    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix) {
        if (i >= n || j >= m) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int right = solve(i, j + 1, n, m, matrix);
        int diag  = solve(i + 1, j + 1, n, m, matrix);
        int down  = solve(i + 1, j, n, m, matrix);
        
        int curr = 0;
        if (matrix[i][j] == 1) {
            curr = 1 + min({right, diag, down});
            ans += curr; // add all squares ending here
        }
        
        return dp[i][j] = curr;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        ans = 0; // Reset for multiple test cases
        dp = vector<vector<int>>(n, vector<int>(m, -1)); // Initialize memoization table
        solve(0, 0, n, m, matrix);
        return ans;
    }
};