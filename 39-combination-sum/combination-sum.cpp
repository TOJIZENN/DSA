class Solution {
public:
void solve(int i,vector<int>& candidates,vector<vector<int>>&ans,vector<int>temp,int target,int curr)
{
    if(curr==target){ans.push_back(temp);return;}
    if(i>=candidates.size() || curr>target){return;}
    temp.push_back(candidates[i]);
    solve(i,candidates,ans,temp,target,curr+candidates[i]);
    temp.pop_back();
    solve(i+1,candidates,ans,temp,target,curr);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        int curr=0;
        solve(0,candidates,ans,temp,target,curr);
        return ans;
    }
};