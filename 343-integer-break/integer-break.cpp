class Solution {
public:
    void solve(int i, vector<int>& nums, long curr, int n,long& ans)
    {
        if (i >= nums.size()) return;
        if (n < 0) return;
        if (n == 0) {
            ans = max(ans, curr);
            return;
        }

        // Include nums[i]
        solve(i, nums, curr * nums[i], n - nums[i], ans);

        // Exclude nums[i]
        solve(i + 1, nums, curr, n, ans);
    }

    int integerBreak(int n) 
    {
        vector<int> nums;
        for (int i = 1; i <= n - 1; i++) {
            nums.push_back(i);
        }

        long curr = 1;
        long ans = INT_MIN;
        solve(0, nums, curr, n, ans);
        return ans;
    }
};
