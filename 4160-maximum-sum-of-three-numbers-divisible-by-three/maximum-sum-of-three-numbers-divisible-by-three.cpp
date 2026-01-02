class Solution {
public:
    int n;
    int dp[100005][4][3];

    int solve(vector<int>& nums, int i, int cnt, int mod) {
        if (cnt == 3)
            return (mod == 0) ? 0 : -1e9;

        if (i == n) return -1e9;

        int &res = dp[i][cnt][mod];
        if (res != -1) return res;

        int notPick = solve(nums, i + 1, cnt, mod);

        int pick = nums[i] +
                   solve(nums, i + 1, cnt + 1, (mod + nums[i]) % 3);

        return res = max(pick, notPick);
    }

    int maximumSum(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums, 0, 0, 0);
        return max(0, ans);
    }
};
