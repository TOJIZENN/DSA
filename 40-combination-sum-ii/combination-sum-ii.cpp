class Solution {
public:
 vector<vector<int>>ans;
void solve(int i,vector<int>& candidates, int target,vector<int>temp)
{
    if(target==0){ans.push_back(temp);return;}
    if(i>=candidates.size() || target<0){return;}
    if(target-candidates[i]>=0)
    {
        temp.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],temp);
        temp.pop_back();
    }
    while(i+1<candidates.size() && candidates[i]==candidates[i+1]){i++;}
    solve(i+1,candidates,target,temp);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
       vector<int>temp;
       sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,temp);
        return ans;

    }
};