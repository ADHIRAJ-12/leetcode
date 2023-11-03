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

   void preorder(TreeNode* root,vector<int> &ans){
    if(root){
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
     }
   }

    vector<int> findMode(TreeNode* root) {
        vector<int>ans,res;
        preorder(root,ans);

        unordered_map<int,int>m;
        for(int i=0;i<ans.size();i++){
            m[ans[i]]++;
        }
        int maxi=INT_MIN,val=0;
        for(auto i:m){
            if(i.second>maxi){
            maxi=i.second;
            val=i.first;
            
            }
        }
        //for more than one mode
        for(auto i:m){
            if(i.second==maxi){
                res.push_back(i.first);
            }
        }
        return res;
    }
};