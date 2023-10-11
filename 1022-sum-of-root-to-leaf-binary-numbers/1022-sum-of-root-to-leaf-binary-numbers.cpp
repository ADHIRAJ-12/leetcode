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
    
    int ans=0;
    
    void preorder(TreeNode* root,string a){
       
        if(root==NULL)return;
        
        a.push_back('0'+(root->val));
        if(root->left==NULL && root->right==NULL)ans=ans+stoi(a,nullptr,2);
        
        preorder(root->left,a);
        preorder(root->right,a);

    }


    int sumRootToLeaf(TreeNode* root) {
           string temp="";
           preorder(root,temp);
           return ans;
    }
};