class Solution {
public:
void solve(int i,set<vector<int>>&st,vector<int>&temp,vector<int>& nums,int n)
{
    if(i>=n)
    {
        st.insert(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(i+1,st,temp,nums,n);
    temp.pop_back();
    solve(i+1,st,temp,nums,n);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        set<vector<int>>st;
       sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        int n=nums.size();
        solve(0,st,temp,nums,n);
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};