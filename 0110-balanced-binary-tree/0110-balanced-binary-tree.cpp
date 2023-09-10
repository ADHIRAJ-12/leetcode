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
    
    
int findMaxDepth(TreeNode*root) 
{
	//Write your code here. 
    if(root==NULL)return 0;

    int left=findMaxDepth(root->left);
    int right=findMaxDepth(root->right);
    
    if(left==-1 || right==-1)return -1;
    
    if(abs(left-right)>1)return -1;
    
    else return 1+max(left,right);
}

    
    
    bool isBalanced(TreeNode* root) {
        
        int a=findMaxDepth(root);
        if(a==-1)return false;
        else return true;
        
        
    }
};