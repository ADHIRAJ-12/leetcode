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
    
    TreeNode* solve(TreeNode * root,int value){
        
        if(root==NULL){
            root=new TreeNode(value);
            return root;
        }
        
        root->right=solve(root->right,value);
        // else  root->left=solve(root->left,value);
        
        return root;
    }
    
    void inorder(vector<int>&temp,TreeNode* root){
        
        if(root==NULL)return;
        inorder(temp,root->left);
        temp.push_back(root->val);
        inorder(temp,root->right);
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
       
        vector<int>temp;
        inorder(temp,root);
        
        TreeNode* node=NULL;
        for(int i=0;i<temp.size();i++){
            int value=temp[i];
            node=solve(node,value);
        }
        return node;
    }
};