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
    
    vector<TreeNode*> solve(int n){
       
        vector<TreeNode*>v;
        
        if(n==1){
            TreeNode* node= new TreeNode(0);
            v.push_back(node);
            return v;
        }
        
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left=solve(i);
            vector<TreeNode*> right=solve(n-i-1);
            
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    v.push_back(root);
                }
            }
        }
        return v;
        
    }
    
    
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};