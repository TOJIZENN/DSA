class Solution {
public:
void solve(vector<int>& nums,set<vector<int>> &st,vector<int>temp,int n,int i)
{
    if(i>n)
    {
        st.insert(temp);
        return;
    }
    temp.push_back(nums[i]);
    solve(nums,st,temp,n,i+1);
    temp.pop_back();
    solve(nums,st,temp,n,i+1);

}
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        set<vector<int>>st;
        vector<int>temp;
        int n=nums.size()-1;
        solve(nums,st,temp,n,0);
        vector<vector<int>>vt;
        for(auto x:st)
        {
            vt.push_back(x);
        }
        return vt;
    }
};