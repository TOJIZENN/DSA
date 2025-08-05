class Solution {
public:
int solve(int idx,int curr,vector<int>& nums, int target,int n)
{
if(idx>=n){if(curr==target){return 1;}else{return 0;}}

int plus=solve(idx+1,curr+nums[idx],nums,target,n);
int minus=solve(idx+1,curr-nums[idx],nums,target,n);
return plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n=nums.size();
        return solve(0,0,nums,target,n);
    }
};