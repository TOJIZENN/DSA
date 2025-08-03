class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        set<int>st(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int a=arr[i],b=arr[j],l=2;
                while(st.count(a+b))
                {
                    b=a+b;
                    a=b-a;
                    l++;
                }
                ans=max(ans,l);
            }
        }
        return ans>2? ans:0;
    }
};