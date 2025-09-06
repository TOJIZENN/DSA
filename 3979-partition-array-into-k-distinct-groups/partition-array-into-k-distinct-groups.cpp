class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) 
    {
        if(nums.size()%k!=0){return false;}
        unordered_map<int,int>mp;

        for(auto it:nums)
        {
            mp[it]++;
        }
         for(auto it:mp)
         {
            if(it.second>nums.size()/k){return false;}
         }

        return true;
    }
};