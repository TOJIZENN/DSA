class Solution {
public:
int dp[501][501];
int solve(int i,int j,vector<int>& piles)
{
if(i>j){return 0;}
if(dp[i][j]!=-1){return dp[i][j];}
int take=piles[i]+solve(i+1,j-1,piles);
int stake=piles[j]+solve(i+1,j-1,piles);
dp[i][j]=max(take,stake);
return dp[i][j];
}
    bool stoneGame(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        int i=0;
        int j=piles.size()-1;
        int total = accumulate(piles.begin(), piles.end(), 0);
        int alice=solve(i,j,piles);
        int bob=total-alice;
        if(alice>bob){return true;}
        return false;
    }
};