class Solution {
public:
    int scoreOfString(string s) 
    {
        vector<int>v;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
         v.push_back(s[i]-'a');
        }
        for(int j=0;j<s.size()-1;j++)
        {
            ans+=abs(v[j+1]-v[j]);
        }
 return ans;   
    }
};