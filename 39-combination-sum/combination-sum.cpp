class Solution {
public:
    void solve(int i,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&temp,int currsum)
    {
        if(currsum>=target || i==candidates.size()){
            if(currsum==target){
            ans.push_back(temp);
            return;
                }
            else if(currsum>target){
                return;
            }
        }
        if(i<=candidates.size()-1)
        {
         temp.push_back(candidates[i]);
         currsum+=candidates[i];
         solve(i,candidates,target,ans,temp,currsum);
         temp.pop_back();
         currsum-=candidates[i];
         solve(i+1,candidates,target,ans,temp,currsum);
        }
         
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        int currsum=0;
        solve(0,candidates,target,ans,temp,currsum);
        return ans;
    }
};