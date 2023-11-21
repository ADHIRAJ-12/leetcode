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
    TreeNode* temp=NULL;
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        //base case
        if(depth==1){
            temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        
        //node,depth
        queue<pair<TreeNode*,int>>q;
         q.push({root,1});
        
        while(true){
            //travese untill you reach depth-1 level;
            int level=q.front().second;
            TreeNode* node=q.front().first;
            
            if(level==depth-1)break;
            if(node->left!=NULL)q.push({node->left,level+1});
            if(node->right!=NULL)q.push({node->right,level+1});
                       
            q.pop();

            
        }
        
        while(!q.empty()){
            
            temp=q.front().first->left;
            q.front().first->left=new TreeNode(val);
            q.front().first->left->left=temp;
            
            temp=q.front().first->right;
            q.front().first->right=new TreeNode(val);
            q.front().first->right->right=temp;
            
            q.pop();
            
        }
        
        return root;
    }
};