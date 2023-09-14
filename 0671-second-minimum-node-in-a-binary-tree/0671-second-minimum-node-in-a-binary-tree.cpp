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
    
    void inorder(TreeNode* root,set<int>&ans){
        
        if(!root)return;
        ans.insert(root->val);
        inorder(root->left,ans);
        inorder(root->right,ans);
        
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        
        set<int>ans;
        inorder(root,ans);
        auto it = next(ans.begin(),1);
        if(ans.size()==1)return -1;
        else return *it;
       
    }
};