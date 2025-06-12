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
    TreeNode* lca(TreeNode* root,int src,int dest)
{
    if(!root){return NULL;}
    if(root->val==src || root->val==dest){return root;}
    TreeNode* l=lca(root->left,src,dest);
    TreeNode* r=lca(root->right,src,dest);
    if(l&&r){return root;}

    return l?l:r;

}
      bool findpath(TreeNode* l_ca,int target,string& path)
      {
        if (l_ca == NULL) return false;
if (l_ca->val == target) return true;
        path.push_back('L');
        if(findpath(l_ca->left,target,path)==true){return true;}
        path.pop_back();
         path.push_back('R');
         if(findpath(l_ca->right,target,path)==true){return true;}
                path.pop_back();
                return false;

      }
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        TreeNode* l_ca=lca(root,startValue,destValue);

        string lcatosrc="";
        string lcatodest="";

        findpath(l_ca,startValue,lcatosrc);
        findpath(l_ca,destValue,lcatodest);
        string ans="";

        for(int i=0;i<lcatosrc.size();i++)
        {
            ans.push_back('U');
        }
        ans+=lcatodest;
        return ans;


        
    }
};