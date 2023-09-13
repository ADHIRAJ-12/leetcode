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


bool f(TreeNode *root, int x,string &ans){
    
    if(root->val==x)return true;
    
    if(root->left && f(root->left,x,ans) )ans.push_back('L');
   else if(root->right && f(root->right,x,ans))ans.push_back('R');

   return !ans.empty();

}
    
    
    string getDirections(TreeNode* root, int start, int dest) {
        string ans,temp;
        
        f(root,start,ans);
        f(root,dest,temp);
       
        while(!ans.empty() && ! temp.empty() && ans.back()==temp.back()){
            ans.pop_back();
            temp.pop_back();
        }
        return string(ans.size(),'U')+string(temp.rbegin(),temp.rend());
        
    }
};