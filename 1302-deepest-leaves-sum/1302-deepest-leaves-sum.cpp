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
    int sum=0,maxdepth=-1;    
    
    void solve(TreeNode* root,int depth){
        
        //if root doesnt exists return
          if(!root)return;
        
        
        //if you reach a node that if leaf node 
        if(!root->left && !root->right){
      
        
        //and its curr depth >max depth then upadate the maxdepth and the sum
        if(depth>maxdepth){
            maxdepth=depth;
            sum=root->val;
        }
        
        //if you again encounter a node present at the same depth then add it to the sum
        else if(depth==maxdepth)sum+=root->val;
        
        //return after all procesing
            
            return;
        }
        
        //recurssive calls for the left and right part
        
        solve(root->left,depth+1);
        solve(root->right,depth+1);

        
    }
    
    int deepestLeavesSum(TreeNode* root) {
      
        solve(root,0);
        return sum;
    }
};