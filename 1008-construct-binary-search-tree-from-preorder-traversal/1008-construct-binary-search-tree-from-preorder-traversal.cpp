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
    TreeNode* f(vector<int> &preOrder,int &s,int ub){

        if(s==preOrder.size() || preOrder[s]>ub )return NULL;
        TreeNode* root=new TreeNode(preOrder[s++]);
        root->left=f(preOrder,s,root->val);
        root->right=f(preOrder,s,ub);

        return root;
}

    
    TreeNode* bstFromPreorder(vector<int>& preOrder) {
        
        int i=0;
        return f(preOrder,i,INT_MAX);
        
    }
};