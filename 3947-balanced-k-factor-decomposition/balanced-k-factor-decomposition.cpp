class Solution {
public:
    vector<vector<int>>ans;
    void solve(int start, int n, int k, vector<int> &temp) {
    if (k == 1) {
        temp.push_back(n);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    for (int f = start; f <= n; ++f) {
        if (n % f == 0) {
            temp.push_back(f);
            solve(f, n / f, k - 1, temp);
            temp.pop_back();
        }
    }
}
vector<int> minDifference(int n, int k) {
    ans.clear();
    vector<int> temp;
    solve(1, n, k, temp);
    int bestIdx = 0;
    int bestDiff = INT_MAX;
    for (int i = 0; i < ans.size(); ++i) {
        int lo = *min_element(ans[i].begin(), ans[i].end());
        int hi = *max_element(ans[i].begin(), ans[i].end());
        if (hi - lo < bestDiff) {
            bestDiff = hi - lo;
            bestIdx = i;
        }
    }
    return ans[bestIdx];
}

};