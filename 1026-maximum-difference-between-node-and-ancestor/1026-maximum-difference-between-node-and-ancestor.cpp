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

    int f(TreeNode* root,int maxi,int mini){
    
    if(root==NULL)return maxi-mini;
     
      maxi=max(maxi,root->val);
      mini=min(mini,root->val);

    int left=f(root->left,maxi,mini);
    int right=f(root->right,maxi,mini);

    return max(left,right); 


    }

    int maxAncestorDiff(TreeNode* root) {
       
       return f(root,INT_MIN,INT_MAX);
    }
};