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
    
   void  f(TreeNode* root,vector<int>& a){
       
       if(!root)return;
       f(root->left,a);
       a.push_back(root->val);
       f(root->right,a);
       
   }
    
    
    
    
    int getMinimumDifference(TreeNode* root) {
        vector<int>temp;
        f(root,temp);
        
        int mini=1e8;
        for(int i=0;i<temp.size()-1;i++){
            mini=min(mini,temp[i+1]-temp[i]);
        }
        return mini;
        
    }
};