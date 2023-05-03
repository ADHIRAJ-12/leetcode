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
    private:
     int maxDepth(TreeNode* root) {
        //base case
         if (root==NULL) 
            return 0;     
         
        //recurssive calls for left and right part
        
        int left=maxDepth(root->left);      
        int right=maxDepth(root->right);
       int ans=max(left,right)+1;
        return ans;
        
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
       if(root==NULL)
           return 0;
                   
        int ans1= diameterOfBinaryTree(root->left);
        int ans2= diameterOfBinaryTree(root->right);
        int ans3= maxDepth(root->left)+ maxDepth(root->right);
        
        int ans=max(ans1,max(ans2,ans3));
        return ans;
        
        
        
    }
};



