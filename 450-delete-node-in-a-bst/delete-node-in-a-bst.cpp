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
    TreeNode* solve(TreeNode* root, int key)
    {
        if(!root){return nullptr;}
          if(key>root->val)
          {
            root->right=solve(root->right,key);
          }
         else if(key<root->val){root->left=solve(root->left,key);}
          else
          {
            if (!root->left && !root->right) return nullptr;
            if (!root->left) return root->right;
            if (!root->right) return root->left;  
            root->val=find(root->right);
            root->right=solve(root->right,root->val);
          }
          return root;
    } 
     int find(TreeNode* root)
     {
       while(root->left){root=root->left;}
       return root->val;
     } 
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
     return solve(root,key);   
    }
};