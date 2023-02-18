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
    
    int depth(TreeNode*  root){
        if(!root) return 0;
        
        return 1+max(depth(root->left),depth(root->right));
        
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if(!root)return NULL;
        
        int leftDepth=depth(root->left);
        int rightDepth=depth(root->right);
        
        if(leftDepth==rightDepth)return root;
        if(rightDepth>leftDepth)return lcaDeepestLeaves(root->right);
        else  return lcaDeepestLeaves(root->left);

        
      
    }
};