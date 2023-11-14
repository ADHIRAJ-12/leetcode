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
    
    
    TreeNode* LCA( TreeNode* root, TreeNode* p, TreeNode* q){
        
        
        if(root==NULL || root==p || root== q)return root;
         TreeNode* left=LCA(root->left,p,q);
         TreeNode* right=LCA(root->right,p,q);

         if(left==NULL)return right;
         else if(right==NULL)return left;
         else return root;

        
    }
    
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>v;
        
        while(!q.empty()){
            
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(!q.empty())v.clear();
        }
        TreeNode* lca=v[0];
        for(int i=1;i<v.size();i++){
            TreeNode* temp=v[i];
            lca=LCA(root,lca,temp);
            if(lca==root)break;
        }
        return lca;
        
    }
};