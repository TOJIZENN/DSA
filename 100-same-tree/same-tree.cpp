class Solution {
public:
     void preorder(TreeNode* k,vector<int> &w)
     {
        if(k==nullptr)
        {
            w.push_back(INT_MIN);
            return;}
         w.push_back(k->val);
         preorder(k->left,w);
         preorder(k->right,w);
     }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int>one;
        vector<int>two;
        preorder(p,one);
        preorder(q,two);
        if(one.size()!=two.size()){return false;}
        int n=one.size();
        for(int i=0;i<n;i++)
        {
            if(one[i]!=two[i]){return false;}
        }
          return true;
    }
};