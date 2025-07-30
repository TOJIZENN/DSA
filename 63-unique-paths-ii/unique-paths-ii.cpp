class Solution {
public:
int dp[101][101];
int solve(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid)
{
    if(dp[i][j]!=-1){return dp[i][j];}
     if(i<0 || j<0 || i>=m || j>=n)
    {
        return 0;
    }
    if(i==m-1 && j==n-1 && obstacleGrid[i][j]==0){return 1;}
    if(obstacleGrid[i][j]==1){return 0;}
    return dp[i][j]=solve(i+1,j,m,n,obstacleGrid)+solve(i,j+1,m,n,obstacleGrid);
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        memset(dp,-1,sizeof(dp));
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==0 && n==0){return 1;}
        return solve(0,0,m,n,obstacleGrid);      
    }
};