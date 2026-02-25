class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        long long x = 0;
        while (j < nums.size()) {
            mp[nums[j]]++;
            x += nums[j];
            if (j - i + 1 > k) {
                x -= nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            if (j - i + 1 == k) {
                if (mp.size() == k) {
                    ans = max(ans, x);
                }
            }
            j++;
        }
        return ans;
    }
};