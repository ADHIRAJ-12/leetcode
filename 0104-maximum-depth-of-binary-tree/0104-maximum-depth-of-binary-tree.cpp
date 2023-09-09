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
    
 
    
    int maxDepth(TreeNode* root) {
        int c=0;
     
    if(root==NULL)return c;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int siz=q.size();
        for(int i=0;i<siz;i++){
            
        TreeNode* front=q.front();
        q.pop();
        if(front->left)q.push(front->left);
        if(front->right)q.push(front->right);
            
        }
                c++;


    }

return c;
        
        
    }
};