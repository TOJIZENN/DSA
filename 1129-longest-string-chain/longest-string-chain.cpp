class Solution {
public:
int n;
int dp[1001][1001];
bool isvalid(string &a, string &b)
{
    if (a.size() + 1 != b.size()) return false; 

    int i = 0, j = 0, skipped = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (skipped == 1) return false;
            skipped++;
            j++; 
        }
    }
    return true;
}
int solve(int prev,int curr,vector<string>& words)
{
    if(curr>=n){return 0;}
    if(dp[prev+1][curr]!=-1){return dp[prev+1][curr];}
    int take=0;
    if(prev==-1 || isvalid(words[prev],words[curr]))
    {
        take=1+solve(curr,curr+1,words);
    }
    int notake=solve(prev,curr+1,words);
    dp[prev+1][curr]= max(take,notake);
    return dp[prev+1][curr];
}
    int longestStrChain(vector<string>& words) 
    {
     n=words.size();
    memset(dp,-1,sizeof(dp));
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });
    return solve(-1,0,words); 
    }
};