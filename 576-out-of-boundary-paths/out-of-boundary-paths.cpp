class Solution {
public:
int dp[51][51][51];
int mp;
int np;
int MOD=1e9+7;
int solve(int i,int j,int maxMove)
{
   if (i < 0 || j < 0 || i >= mp || j >= np) return 1;
   if (maxMove==0){return 0;}
   if(dp[i][j][maxMove]!=-1){return dp[i][j][maxMove];}
   
   long long ans=0;
   ans+=solve(i-1,j,maxMove-1);
    ans+=solve(i+1,j,maxMove-1);
     ans+=solve(i,j-1,maxMove-1);
      ans+=solve(i,j+1,maxMove-1);

      return dp[i][j][maxMove]=ans%MOD;

}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        mp=m;
        np=n;
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,maxMove);
        
    }
};