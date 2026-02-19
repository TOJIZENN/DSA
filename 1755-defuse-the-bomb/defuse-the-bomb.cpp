class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> ansi(n,0);
        if(k==0) return ansi;

        // double array
        vector<int> temp1 = code;
        temp1.insert(temp1.end(), code.begin(), code.end());

        // prefix sum
        vector<int> temp2(temp1.size());
        temp2[0]=temp1[0];
        for(int i=1;i<temp1.size();i++)
            temp2[i]=temp2[i-1]+temp1[i];

        vector<int> ans(n);

        for(int i=0;i<n;i++)
        {
            if(k>0)
            {
                int L=i+1;
                int R=i+k;
                ans[i]=temp2[R]-(L>0?temp2[L-1]:0);
            }
            else
            {
                int kk=abs(k);
                int L=i+n-kk;
                int R=i+n-1;
                ans[i]=temp2[R]-(L>0?temp2[L-1]:0);
            }
        }
        return ans;
    }
};
