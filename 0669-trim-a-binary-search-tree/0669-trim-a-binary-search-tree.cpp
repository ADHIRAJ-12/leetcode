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
    
     void dfs(TreeNode* root,vector<int> &v,int low,int high){
        if(root==NULL) return;
        dfs(root->left,v,low,high);
        if(root->val<low || root->val>high)
        v.push_back(root->val);
        dfs(root->right,v,low,high);
    }
    
     TreeNode* find(TreeNode*root){
        
        if(root->right==NULL)return root;
        return find(root->right);
        
    }
    
    TreeNode* helper(TreeNode*  root){
        
        if(root->left==NULL)return root->right;
        else if(root->right==NULL)return root->left;
        
        TreeNode* rightchild=root->right;
        TreeNode* lastright=find(root->left);
        
        lastright->right=rightchild;
        return root->left;
        
        
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)return NULL;
        if(root->val==key)return helper(root);
        
        TreeNode* temp=root;
       while(root!=NULL){
            
               if(root->val>key){
                //go left
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                   else root=root->left;
            }
           
            else{
                //go right
                 if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                     break;
                }
                   else root=root->right;
            }

       }
        
        return temp;
    }
    
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
       vector<int>traversal;
        //containing only nodes to delete
        dfs(root,traversal,low,high);
        
        for(int i=0;i<traversal.size();i++){
            root=deleteNode(root,traversal[i]);
        }
        return root;
    }
};