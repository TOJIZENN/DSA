class Solution {
public:
int n;
int dp[2][101][101];
int solvealice(vector<int>&piles,int person,int i,int M)
{
    if(dp[person][i][M]!=-1)
    {
        return dp[person][i][M];
    }
    if(i>=n){return 0;}
    int ans=(person==1)? -1:INT_MAX;
    int stones=0;
    for(int x=1;x<=min(2*M,n-i);x++)
    {
        stones+=piles[i+x-1];
        if(person==1)
        {
            ans=max(ans,stones+solvealice(piles,0,i+x,max(M,x)));
        }
        else
        {
ans=min(ans,solvealice(piles,1,i+x,max(M,x)));
        }
    }
return dp[person][i][M]=ans;
}
    int stoneGameII(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        n=piles.size();
        return solvealice(piles,1,0,1);
        
    }
};