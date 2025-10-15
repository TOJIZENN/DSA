class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        int cntzero=0;
       int currsum=0;
        while(j<n)
        {
         currsum+=nums[j];
          while(i<j && (nums[i]==0 || currsum>goal))
          {
           if(nums[i]==0)
           {
            cntzero++;
           }
           else
           {
            cntzero=0;
           }
           currsum-=nums[i];
           i++;
          }
          if(currsum==goal)
            {
             ans+=1+cntzero;   
            }
            j++;
        }
        return ans;
        
    }
};