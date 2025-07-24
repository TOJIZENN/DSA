class Solution {
public:
    int n;
    int solve(vector<pair<int,int>>&vec, int prev, int curr,vector<vector<int>>&dp)
    {
        if(curr >= n) return 0;
        if(dp[prev+1][curr]!=-1){return dp[prev+1][curr];}
        int take = 0;
        if(prev == -1 || vec[prev].second <= vec[curr].second)
        {
            take = vec[curr].second + solve(vec, curr, curr+1,dp);
        }
        int notake = solve(vec, prev, curr+1,dp);
        return dp[prev+1][curr]=max(take, notake);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>vec;
        n = scores.size();
        vector<vector<int>>dp(n + 1, vector<int>(n, -1));
        for(int i=0; i<scores.size(); i++)
        {
            vec.emplace_back(ages[i], scores[i]); 
        }
        sort(vec.begin(), vec.end());
        return solve(vec,-1,0,dp);
    }
};