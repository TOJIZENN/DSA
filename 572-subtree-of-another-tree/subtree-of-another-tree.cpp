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
bool solve(TreeNode* a, TreeNode* b)
{
if(!a && !b){return true;}
if(!a||!b){return false;}
if(a->val!=b->val){return false;}
return solve(a->left,b->left) && solve(a->right,b->right);
}

bool helper(TreeNode* root, TreeNode* subRoot)
{
    if(!root) return false;
    if(solve(root,subRoot)){return true;}
        return helper(root->left,subRoot)||helper(root->right,subRoot);

}

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==nullptr){return false;}
        return helper(root,subRoot);           
    }
};