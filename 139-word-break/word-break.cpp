class Solution {
public:
unordered_set<string>st;
int n;
int dp[301];
bool solve(int id,string& s)
{
if(id>=n){return true;}
if (dp[id]!=-1){return dp[id];}
if(st.find(s)!=st.end()){return true;}
for(int i=1;i<=n;i++)
{
    string temp=s.substr(id,i);
    if(st.find(temp)!=st.end() && solve(id+i,s))
    {
        return dp[id]=true;
    }
}
return dp[id]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        for(auto it:wordDict)
        {
            st.insert(it);
        }
        return solve(0,s);
    }
};