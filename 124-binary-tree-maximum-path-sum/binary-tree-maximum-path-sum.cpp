class Solution
{
public:
int ans=INT_MIN;
int solve(TreeNode* node)
{
if(node==nullptr) return 0;
int left=max(0,solve(node->left));
int right=max(0,solve(node->right));

ans=max(ans,left+right+node->val);

return node->val+ max(right,left);
}
    int maxPathSum(TreeNode* root) 
    {
    
    solve(root);
    return ans;
    }
};