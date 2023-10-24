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
    
    bool same(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        if(r1->val != r2->val) return false;
        return same(r1->left, r2->left) && same(r1->right, r2->right);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int siz=q.size();
            while(siz>0){
                TreeNode * temp=q.front();
                q.pop();
               if(same(temp,subRoot)) return true;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                siz--;
            }
        }
        
        return false;
        
    }
};