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
    
    int number(TreeNode* root){
        
        if(!root)return 0;
        
        int left=number(root->left);
        int right=number(root->right);
        return 1+left+right;

    }
       int sum(TreeNode* root){
        
        if(!root)return 0;
        
        int left=sum(root->left);
        int right=sum(root->right);
        return root->val+left+right;

    }
    
    
    int averageOfSubtree(TreeNode* root) {
        
        if(root==NULL)return 0;
        
        int left=averageOfSubtree(root->left);
        int right=averageOfSubtree(root->right);
        
        if((root->val)==(sum(root)/number(root))){
            return 1+left+right;
        }
        return left+right;
        

    }
};