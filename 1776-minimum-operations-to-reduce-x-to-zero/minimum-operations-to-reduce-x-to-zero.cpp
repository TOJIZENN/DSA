class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int sum=0;
        for(auto it:nums){sum+=it;}
        int ans=-1;
        int pref=0;
        int target=sum-x;
        int i=0;
        int j=0;
        int sol=0;
        int n=nums.size();
        while(j<n)
        {
            pref+=nums[j];
            while(pref>target && i<=j){pref-=nums[i];i++;}
            if(pref==target){ans=max(ans,j-i+1);}
            j++;
        }
        return ans==-1?-1:n-ans;
    }
};