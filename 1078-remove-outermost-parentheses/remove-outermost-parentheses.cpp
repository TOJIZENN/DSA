class Solution {
public:
    string removeOuterParentheses(string s) 
    {    
    string ans="";
    int cnt=0;
    for(auto it:s)
    {
        if(it=='(')
        {
            if(cnt>0){ans+=it;}
            cnt++;
        }
        else if(it==')')
        {
            cnt--;
            if(cnt>0){ans+=it;}
            
        }
    }
        return ans;
    }
};