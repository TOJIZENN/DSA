class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_set<int>st;
        int i=0;
        int j=0;
        int ans=0;
        int n=s.size();
        while(j<n)
        {
            if(st.find(s[j])!=st.end())
            {
                st.erase(s[i]);
                i++;
            }
            else
            {
            st.insert(s[j]);
            j++;
            ans=max(ans,j-i);
            }
        }
        return ans;
    }
};