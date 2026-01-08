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
long long ans=0;
long long totSum=0;
const int MOD = 1e9 + 7;
    void sum(TreeNode* root)
    {
         if(!root){return;}
         sum(root->left);
         sum(root->right);
         totSum+=root->val;
    }

long long solve(TreeNode*root )
{
    if(!root) return 0;
    long long left = solve(root->left);
    long long right = solve(root->right);
    long long subsum=left+right+root->val;
    ans=max(ans,subsum*(totSum-subsum));
    return subsum;
}

    int maxProduct(TreeNode* root) 
    {
        sum(root);
        solve(root);
        return ans%MOD;
    }
};