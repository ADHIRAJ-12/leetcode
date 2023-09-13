/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool f( TreeNode* root,  TreeNode* x,vector< TreeNode*>&ans){

    if(!root)return false;
    ans.push_back(root);
    if(root->val == x->val)return true;

    bool l=f(root->left,x,ans);
    bool r=f(root->right,x,ans);
    if(l||r)return true;

    ans.pop_back();
    return false;


}

    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
        
    if(x==y)return x;
    vector< TreeNode*>a,b;
    f(root,x,a);
    f(root,y,b);

    int i=0;
    int mini=min(a.size(),b.size());
    for(i=0;i<mini;i++){
            if(a[i]==b[i])continue;
            else break;
        
    }
    return a[i-1];
        
    }
    
};