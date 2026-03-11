class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        stack<int>st;
        for(auto it:logs)
        {
            if(it=="../")
            {
                if(!st.empty())
                {
  st.pop();
                }
              
            }
            else if(it=="./"){continue;}
            else
            {
                st.push(1);
            }

        }
    return st.size();
    }
};