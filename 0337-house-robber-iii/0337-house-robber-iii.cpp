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
    
    
            // dp solution

    unordered_map<TreeNode *,int>m;

    int rob(TreeNode* root) {        
        
        
        if(root==NULL)return 0;
        
        if(m.find(root)!=m.end()) return m[root];
        
         m[root]=-1;

        
        int x=rob(root->left)+rob(root->right);
        int y=root->val;
        
         if(root->left!=NULL){
            y+=rob(root->left->left)+rob(root->left->right);
        }
        
        if(root->right!=NULL){
            y+=rob(root->right->left)+rob(root->right->right);
        }
        
        m[root]=max(x,y);
        
        return m[root];

    }
};




//         if(root==NULL) return 0;
        
//         int val=0;
//         if(root->left!=NULL){
//             val+=rob(root->left->left)+rob(root->left->right);
//         }
        
//         if(root->right!=NULL){
//             val+=rob(root->right->left)+rob(root->right->right);
//         }
        
//         int leave=rob(root->left)+rob(root->right);
//         int rob=val+root->val;
        
//         return max(leave,rob);
        