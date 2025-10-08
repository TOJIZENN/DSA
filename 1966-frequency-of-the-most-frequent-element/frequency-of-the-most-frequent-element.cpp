class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        sort(nums.begin(),nums.end());
        long long i=0,j=0;
        long n=nums.size();
        long long ans=0;
        long long prefixsum=0;
        while(j<n)
        {
            prefixsum+=nums[j];
            while(nums[j]*(j-i+1)>prefixsum+k)
            {
               prefixsum-=nums[i];
               i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};