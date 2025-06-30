class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<int>& temp, vector<vector<int>>& ans, int& tval, int n) {
        if (tval == target) {
            ans.push_back(temp);
            return;
        }

        if (tval > target || i > n) return;

        // pick current number
        temp.push_back(candidates[i]);
        tval += candidates[i];
        solve(candidates, target, i, temp, ans, tval, n);
        tval -= candidates[i];       // backtrack tval
        temp.pop_back();             // backtrack temp

        // don't pick current number
        solve(candidates, target, i + 1, temp, ans, tval, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size() - 1;
        vector<vector<int>> ans;
        vector<int> temp;
        int tval = 0;
        solve(candidates, target, 0, temp, ans, tval, n);
        return ans;
    }
};
