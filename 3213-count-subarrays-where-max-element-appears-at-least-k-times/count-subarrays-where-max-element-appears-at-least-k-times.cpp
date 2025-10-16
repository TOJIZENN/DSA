class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        priority_queue<int,vector<int>,greater<int>>q;
        int i=0;
        int j=0;
        int n=nums.size();
        long long ans=0;
        int cnt=0;
        int ele=*max_element(nums.begin(),nums.end());
        while(j<n)
        {
            if(nums[j]==ele){cnt++;}
            while(cnt==k)
            {
                ans+=n-j;
                if(nums[i]==ele){cnt--;}
                i++;
            }
            j++;
        }
        return ans;
    }
};