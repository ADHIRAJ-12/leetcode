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
TreeNode* f(vector<int>& inOrder,int is,int ie,vector<int>& postOrder,int ps,int pe,map<int,int>&mp){

     if(ps>pe || is>ie)return NULL;
     TreeNode* root=new TreeNode(postOrder[pe]);
     
     int index=mp[root->val];
     int numleft=index-is;

     root->left=f(inOrder,is,index-1,postOrder,ps,ps+numleft-1,mp);
     root->right=f(inOrder,index+1,ie,postOrder,ps+numleft,pe-1,mp);

     return root;
     
}
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
        
        map<int,int>mp;
     int n=inOrder.size();
     for(int i=0;i<n;i++)mp[inOrder[i]]=i;
     TreeNode* root=f(inOrder,0,n-1,postOrder,0,n-1,mp);
     return root;
        
    }
};