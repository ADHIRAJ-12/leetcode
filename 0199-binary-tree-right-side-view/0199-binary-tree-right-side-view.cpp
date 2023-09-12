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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
                
        vector<vector<int>>ans;
        if(!root) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int siz=q.size();
            vector<int>res;
            
            for(int i=0;i<siz;i++){
                
            TreeNode* temp=q.front();
                q.pop();
                res.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
 
            ans.push_back(res);
        }
        
        return ans;
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
         
        vector<vector<int>>res= levelOrder(root);
        vector<int>ans;

    for(int i=0;i<res.size();i++){
        int j=res[i].size();
            ans.push_back(res[i][j-1]);
        }
        
        return ans;
    
    }
};