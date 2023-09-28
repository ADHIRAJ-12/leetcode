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



 class NodeValue{

         public:
         int maxNode,minNode,maxSize;

         NodeValue(int minNode,int maxNode,int maxSize){
             this->minNode=minNode;
             this->maxNode=maxNode;
             this->maxSize=maxSize;
         }

     };

    int maxi=INT_MIN;


class Solution {
public:
    
    NodeValue f(TreeNode* root){

        //postorder
        if(!root)return NodeValue(INT_MAX,INT_MIN,0);

        auto left=f(root->left);
        auto right=f(root->right);

        if(left.maxNode<root->val && right.minNode>root->val){
            
             maxi=max({maxi,left.maxSize+right.maxSize+root->val});
            
            return NodeValue(min(left.minNode,root->val),
            max(right.maxNode,root->val),
            root->val+left.maxSize+right.maxSize);
        
        }

        return  NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));


    }

    
    int maxSumBST(TreeNode* root) {
        
        maxi=INT_MIN;
        NodeValue a= f(root);
        return (maxi<0)?0:maxi;
    }
};