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
    
    void f(TreeNode* node,int &c){
        
        if(!node->left && !node->right)return;
        if(node->left)f(node->left,c+=1);
       if(node->right) f(node->right,c+=1);
        
        
    }
    
    
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int c=1;
        f(root,c);
        return c;
    }
};