class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        int count = 0;         // number of non-null nodes
        int lastIndex = 0;     // max index assigned
        
        while (!q.empty()) {
            auto [node, idx] = q.front();
            q.pop();
            
            if (node) {
                count++;
                lastIndex = idx;
                q.push({node->left, 2 * idx + 1});
                q.push({node->right, 2 * idx + 2});
            }
        }
        
        return lastIndex == count - 1;
    }
};
