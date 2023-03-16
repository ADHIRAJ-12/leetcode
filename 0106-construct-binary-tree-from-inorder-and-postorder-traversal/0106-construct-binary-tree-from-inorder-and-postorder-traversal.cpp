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
    
     int findPosition(vector<int> in, int element, int n){
        
        for(int i=0;i<n;i++){
            if(in[i]==element)
                return i;
        }
        return -1;
    }
                     
                    
      TreeNode *solve(vector<int> postorder, vector<int> inorder,int &index,int inOrderStart,int inOrderEnd,int n){
          
          if(index<0 || inOrderStart>inOrderEnd){
              return NULL;
          }
          
          int element=postorder[index--];
            TreeNode *root=new TreeNode (element);
          int position=findPosition(inorder,element,n);
                      root->right=solve(postorder,inorder,index,position+1,inOrderEnd,n);

          root->left=solve(postorder,inorder,index,inOrderStart,position-1,n);
            return root;
          
      }               
                     
                     
                     
                     
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postorderIndex=n-1;
        
         TreeNode * ans=solve(postorder,inorder,postorderIndex,0,n-1,n);
        return ans;
    }
};
   