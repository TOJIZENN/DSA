class Solution {
public:
    bool valid(string str) {
        int n = str.size() - 1;
        if ((str[0] == 'a' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' ||
             str[0] == 'e') &&
                (str[n] == 'a' ||
            str[n] == 'e' || str[n] == 'i' || str[n] == 'o' || str[n] == 'u')) {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> temp;
         vector<int> ans;
        int k = 0;
        for (auto it : words) {
            if (valid(it)) {
                k++;
                 temp.push_back(k);
            }
            else
            {
            temp.push_back(k);
        }
        }
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==r)
            {
                if(valid(words[r])){ans.push_back(1);}
                else
                {
                    ans.push_back(0);
                }

            }
           else if(l==0)
            {
                ans.push_back(temp[r]);
            }
           else
{
    int x = temp[r] - temp[l-1];
    ans.push_back(x);
}
        }
        return ans;
    }
};