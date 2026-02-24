class Solution {
public:
    int takeCharacters(string s, int k)
    {
        int ans=s.size();
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;
        while(j<s.size())
        {
            mp[s[j]]--;
            while(mp['a']<k || mp['b']<k || mp['c']<k)
            {
                mp[s[i]]++;
                i++;
            }
              if(mp['a']>=k && mp['b']>=k && mp['c']>=k)
              {
                int x=j-i+1;
                x=s.size()-x;
                ans=min(ans,x);
              }
              j++;
        }
        return ans;
    }
};