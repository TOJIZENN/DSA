class Solution {
public:
    const unsigned int M = 1000000007;

    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> left, right;

        // Step 1: Count all elements in right map
        for (int num : nums) {
            right[num]++;
        }

        // Step 2: Iterate with each index j as the center of the triplet
        for (int j = 0; j < nums.size(); j++) {
            right[nums[j]]--; // current element is no longer in the right part

            int target = nums[j] * 2;

            int leftCount = left[target];
            int rightCount = right[target];

            ans = (ans + 1LL * leftCount * rightCount % M) % M;

            left[nums[j]]++; // move nums[j] to the left part
        }

        return ans;
    }
};
