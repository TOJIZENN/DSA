class Solution {
public:
    int maxFrequency(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        long long prefixsum=0;
        long long j=0;
        long long ans=INT_MIN;
        long long i=0;
        long long n=nums.size();
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