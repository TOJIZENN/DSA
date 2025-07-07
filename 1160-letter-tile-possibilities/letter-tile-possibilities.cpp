class Solution {
public:
void solve(string &tiles,vector<bool>&vis,int &ans)
{
    for(int i=0;i<tiles.size();i++)
    {
        if(vis[i]==true){continue;}
        if(i>0 && tiles[i]==tiles[i-1] && !vis[i-1]){continue;}
        vis[i]=true;
        ans++;
        solve(tiles,vis,ans);
        vis[i]=false;
    }

}
    int numTilePossibilities(string tiles) 
    {
     int  ans=0;
     sort(tiles.begin(),tiles.end());
   vector<bool> vis(tiles.size(),false);
      solve(tiles,vis,ans);
        return ans;
    }
};