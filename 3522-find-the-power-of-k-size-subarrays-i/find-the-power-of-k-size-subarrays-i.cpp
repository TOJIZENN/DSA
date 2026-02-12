class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int zero=0;
        vector<int> temp;
        vector<int> ans;
        temp.push_back(1);
        for(int i=1;i<nums.size();i++)
        {
          if(nums[i]==nums[i-1]+1){
            temp.push_back(1);
          }
          else
          {
            temp.push_back(0);
          }
        }
        int j=0;
        int i=0;
        while(j<nums.size())
        {
            if(j>i && temp[j]==0) zero++;

             if(j-i+1>k)
          {
            if(i+1<=j && temp[i+1]==0) zero--;

            i++;
          }
           
            if(j-i+1==k)
            {
            if(zero==0)
            {
                ans.push_back(nums[j]);
            }
            else{ans.push_back(-1);}
            }
        j++;
        }
        return ans;
    }
};