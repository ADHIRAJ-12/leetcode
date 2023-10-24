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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        long int maxi=-9999999999;
        
        if(root==NULL)return ans;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size>0){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val>maxi)maxi=temp->val;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            size--;
            }
             ans.push_back(maxi);
            maxi=-9999999999;
        }
        return ans;
    }
};