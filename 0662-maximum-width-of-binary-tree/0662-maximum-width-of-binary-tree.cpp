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
    int widthOfBinaryTree(TreeNode* root) {
      
    if(root==NULL)return 0;

    int res=0;
    queue<pair<TreeNode*,int>>q;
    q.push({root,1});   //node and index pushed


     while(!q.empty()){
         int size=q.size();

         int mini=q.front().second; ///min index at that level
         int mn,mx;

         for(int i=0;i<size;i++){
             
             //for preventing overflow, it changes the curr index of each level
             //by decresing min index
             int curr=q.front().second-mini+1;

             TreeNode*temp=q.front().first;
             q.pop();


             if(i==0)mn=curr;
             if(i==size-1)mx=curr;


             if(temp->left!=NULL)q.push({temp->left,2LL*curr});
             if(temp->right!=NULL)q.push({temp->right,2LL*curr +1});  

         }
         res=max(res,mx-mn+1);
     }
     return res;
    
    }
};

           //link attached in notes