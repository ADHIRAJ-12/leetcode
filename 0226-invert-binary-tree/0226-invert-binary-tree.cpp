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
    TreeNode* invertTree(TreeNode* root) {
        
        //if root doesn't exists return
        
        if(!root) return NULL;
        
        //swapping with the help of 3rd variable
            
        TreeNode* temp=NULL;
        temp= root->left;
        root->left=root->right;
        root->right=temp;
        
        //recurssive calls 
        
        invertTree(root->left);
        invertTree(root->right);

        return root;

   
    }
};