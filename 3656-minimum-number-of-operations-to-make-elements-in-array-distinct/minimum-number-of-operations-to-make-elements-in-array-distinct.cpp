class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int n=nums.size()-1;
        int num=0;
        set<int>st;
        int ans=0;
        for(int j=n;j>=0;j--)
        {
        if(st.find(nums[j])!=st.end())
        {
            num=j+1;
            if(num%3==0){ans=num/3;}
            else{ans=(num/3)+1;}
            return ans;
        }
        st.insert(nums[j]);
        }
    return 0;
    }
};