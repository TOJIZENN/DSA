class Solution {
public:
int dp[301][301];
int ans=0;
int solve(int i,int j,int n,int m,vector<vector<char>>& matrix)
{
    if(i>=n ||j>=m){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int right=solve(i,j+1,n,m,matrix);
    int down=solve(i+1,j,n,m,matrix);
    int diag=solve(i+1,j+1,n,m,matrix);
if(matrix[i][j]=='1')
{
    dp[i][j]=1+min({right,down,diag});
    ans=max(ans,dp[i][j]);
}
else {dp[i][j]=0;}
return dp[i][j];
}
    int maximalSquare(vector<vector<char>>& matrix)
    {
    memset(dp,-1,sizeof(dp));
    int n=matrix.size();
    int m=matrix[0].size();
    solve(0,0,n,m,matrix);
    return ans*ans;
    }
};