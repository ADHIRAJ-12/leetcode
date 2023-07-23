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
       
        vector<vector<TreeNode*>>dp(n+1);
        if(n % 2 == 0)return {};
        
//         TreeNode* node= new TreeNode(NULL);
//         TreeNode* nodee=new TreeNode(0);
//         dp[0]={};
//         dp[1]={0};
        
        vector<TreeNode*>v;
        if(n==1){
            TreeNode* node= new TreeNode(0);
            v.push_back(node);
            return v;
        }
        
        if(dp[n].size()!=0)return dp[n];
        
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
         return dp[n]=v;
        
    }
    
    
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};