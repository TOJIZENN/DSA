/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int dx=0;
int dy=0;
TreeNode* px,*py;
    void solve(TreeNode* node,TreeNode* Par, int x, int y,int d)
{
    if(!node){return;}
    if(node->val==x)
    {
     dx=d;
     px=Par;
    }
    if(node->val==y)
    {
      dy=d;
      py=Par;
    }
      solve(node->left,node,x,y,d+1);
      solve(node->right,node,x,y,d+1);
}
    bool isCousins(TreeNode* root, int x, int y) 
    {
        solve(root,nullptr,x,y,0);
           return(dx==dy && px!=py);
        
    }
};