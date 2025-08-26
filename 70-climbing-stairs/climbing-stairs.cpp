class Solution {
public:
int dp[45];
int solve(int i,int n)
{
    if(i>n){return 0;}
    if(i==n){return 1;}
    if(dp[i]!=-1){return dp[i];}
    int one=solve(i+1,n);
    int two=solve(i+2,n);
    dp[i]=(one+two);
    return dp[i];
}
    int climbStairs(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,n); 
    }
};