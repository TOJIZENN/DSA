class Solution {
public:
int n1,n2,n3;
int dp[500][500];
bool solve(int i,int j,int k,string s1, string s2, string s3)
{
if(i>=n1 && j>=n2 && k>=n3){return true;}
if(dp[i][j]!=-1){return dp[i][j];}
if(s1[i]==s3[k]&&s2[j]!=s3[k])
{
return dp[i][j]=(solve(i+1,j,k+1,s1,s2,s3));
}
else if(s1[i]!=s3[k]&&s2[j]==s3[k])
{
return dp[i][j]=solve(i,j+1,k+1,s1,s2,s3);
}
else if(s1[i]==s3[k]&&s2[j]==s3[k])
{
    return dp[i][j]=(solve(i+1,j,k+1,s1,s2,s3)||solve(i,j+1,k+1,s1,s2,s3));
}
return dp[i][j]=false;
}
    bool isInterleave(string s1, string s2, string s3) 
    {
        memset(dp,-1,sizeof(dp));
        if(s1.length() + s2.length() != s3.length()){return false;}
        if(!s1.empty() && s2.empty() && s3!=s1){return false;}
        if(!s2.empty() && s1.empty() && s3!=s2){return false;}
        n1=s1.size();
        n2=s2.size();
        n3=s3.size();
        return solve(0,0,0,s1,s2,s3);
    }
};