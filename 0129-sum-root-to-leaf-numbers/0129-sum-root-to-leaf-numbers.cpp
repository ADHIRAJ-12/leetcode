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
    
    int solve( int sum,TreeNode* root){
        
        if(root==NULL)return 0;
        sum=sum*10+root->val;
        if(root->left==NULL && root->right==NULL)return sum;
        
        int left=solve(sum,root->left);
        int right=solve(sum,root->right);
        
        return left+right;
   
    }
    
    
    int sumNumbers(TreeNode* root) {
        int sum=0;
        return  solve(sum,root);
        
    }
};