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

    void f(TreeNode* root,bool& flag,int num){
        
        if(!root)return;
        if(root->val!=num)flag=false;
        f(root->left,flag,num);
        f(root->right,flag,num);
        
    }
        
    bool isUnivalTree(TreeNode* root) {
       
       bool flag=true;
        int num=root->val;
       f(root,flag,num);
       return flag;
    
    }
};