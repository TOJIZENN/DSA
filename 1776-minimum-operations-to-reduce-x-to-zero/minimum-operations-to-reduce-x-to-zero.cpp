class Solution {
public:
    // int solve(int i,int j,vector<int>& nums, int x,int ans,vector<vector<int>>&dp)
    //  {
    //      if(x==0){return ans;}
    //      if(i>j){return INT_MAX;}
    //      if(dp[i][j]!=-1){return dp[i][j];}
    //      int l=solve(i+1,j,nums,x-nums[i],ans+1,dp);
    //      int r=solve(i,j-1,nums,x-nums[j],ans+1,dp);
    //      return dp[i][j]=min(l,r);
    //  }
    // int minOperations(vector<int>& nums, int x) 
    // {
    //     int n=nums.size();
    //    vector<vector<int>> dp(n, vector<int>(n, -1));
    //     int i=0;
    //     int j=nums.size()-1;
    //     int ans=solve(0,j,nums,x,0,dp);
    //     return ans==INT_MAX? -1:ans;
        
    // }
     int minOperations(vector<int>& nums, int x) 
    {
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        int ans=-1;
        int target=sum-x;
        int i=0;
        int pref=0;
        int j=0;
        int sol=0;
        int n=nums.size();
        bool val=false;
        while(j<n)
        {
            pref+=nums[j];
            while(pref>target && i<=j){pref-=nums[i];i++;}
            if(pref==target){ans=max(ans,j-i+1);}
            j++;
        }
    
    return ans==-1? -1:n-ans;
    }
};