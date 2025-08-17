class Solution {
public:
    long long dp[100005][2]; // memo: index, parity (0=even, 1=odd)

    long long solve(int i, vector<int>& nums, int parity) {
        if (i == nums.size()) return 0;
        if (dp[i][parity] != -1) return dp[i][parity];

        // Option 1: take nums[i]
        long long take;
        if (parity == 0) { // even index in subsequence → add
            take = nums[i] + solve(i + 1, nums, 1);
        } else {           // odd index in subsequence → subtract
            take = -nums[i] + solve(i + 1, nums, 0);
        }

        // Option 2: skip nums[i]
        long long skip = solve(i + 1, nums, parity);

        return dp[i][parity] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0); // start with even position
    }
};