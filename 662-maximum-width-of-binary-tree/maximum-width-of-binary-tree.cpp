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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long int ans=INT_MIN;
        while(!q.empty())
       {
        int n=q.size();
        long long int x=q.front().second;
        long long int y=q.back().second;
        ans=max(ans,y-x);
        for(int i=0;i<n;i++)
        {
            pair<TreeNode*,long long int> it=q.front();
            q.pop();
         if(it.first->left){q.push({it.first->left,(2*it.second)+1});}
         if(it.first->right){q.push({it.first->right,(2*it.second)+2});}
        }
       }
        return ans+1;
    }
};