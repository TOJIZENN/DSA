class Solution {
public:
int dp[300][300];
bool solve(int i ,int j,string &s,set<string>&st)
{
    if(j>s.size()){return false;}
     if (j == s.size()) {
            return st.count(s.substr(i, j - i));
        }
        if(dp[i][j]!=-1){return dp[i][j];}
    bool take=false;
    if(st.find(s.substr(i,j-i))!=st.end())
    {
     take=solve(j,j+1,s,st);
    }
bool notake=solve(i,j+1,s,st);
return dp[i][j]=notake || take;
}
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        memset(dp,-1,sizeof(dp));
        set<string>st(wordDict.begin(),wordDict.end());
        return solve(0,1,s,st);  
    }
};