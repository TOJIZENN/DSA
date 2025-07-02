class Solution {
public:
    void solve(int idx,int target,vector<int>& candidates,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0)
        {
            return;
        }

        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
            {
                continue;
            }
            temp.push_back(candidates[i]);
            solve(i+1,target-candidates[i],candidates,ans,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>temp;
        solve(0,target,candidates,ans,temp);
        return ans;
        
    }
};