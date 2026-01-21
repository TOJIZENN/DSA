/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int key) {

        if (!root) {
            return nullptr;
        }
        else if (root->val > key) {
            root->left = solve(root->left, key);
        }
        else if (root->val < key) {
            root->right = solve(root->right, key);
        } else {
            if (!root->left && !root->right) {
                return nullptr;
            }
            else  if (!root->left) {
                return root->right;
            }
            else if (!root->right) {
                return root->left;
            }
            root->val = find(root->right);
            root->right = solve(root->right, root->val);
        }
        return root;
    }

    int find(TreeNode* root) {
        while (root->left) {
            root=root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) { 
        return solve(root, key); }
};