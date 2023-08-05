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

    vector<TreeNode*>f (int start,int end){
     
     vector<TreeNode*>ans;
     if(start>end){
     ans.push_back(NULL);
     return ans;
     }

     for(int i=start;i<=end;i++){
       vector<TreeNode*>left=f(start,i-1);
       vector<TreeNode*>right=f(i+1,end);

       for(auto j:left){
           for(auto k:right){
                TreeNode* root=new TreeNode(i);
                root->left=j;
                root->right=k;
                ans.push_back(root);
           }
       }

     }
        return ans;

    }

    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return vector<TreeNode*>(0);

        return f(1,n);
    }
};