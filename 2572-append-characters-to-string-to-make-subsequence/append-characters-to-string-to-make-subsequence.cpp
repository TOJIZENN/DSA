class Solution {
public:
    int appendCharacters(string s, string t) 
    {
       int j=0;
       int i=0;
       while(j<s.size())
       {
        if(t[i]==s[j])
        {
            i++;
        }
        j++;
       } 
        return t.size()-i;
    }
};