class Solution {
public:
int mod = 1e9 + 7;
    int solve(int low, int high, int zero, int one, int cnt,vector<int> &dp) {
        if (cnt > high) return 0;
        if(dp[cnt]!=-1){return dp[cnt];}
        int count = 0;
        if (cnt >= low) count = 1;
        int append_zero = solve(low, high, zero, one, cnt + zero,dp);
        int append_one = solve(low, high, zero, one, cnt + one,dp);
        return dp[cnt]=(count + append_zero + append_one)%mod;
    }

    int countGoodStrings(int low, int high, int zero, int one)
    {
          vector<int> dp(high + 1, -1);
        return solve(low, high, zero, one, 0,dp);
    }
};
