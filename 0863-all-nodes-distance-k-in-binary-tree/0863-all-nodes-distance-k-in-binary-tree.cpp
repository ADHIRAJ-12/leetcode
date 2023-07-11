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
    
    void setparent(TreeNode* root, unordered_map<TreeNode* ,TreeNode* > &parent, TreeNode* target){
      
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
          TreeNode* top=q.front();
          q.pop();
          if(top->left){
               parent[top->left]=top;
              q.push(top->left);
             
          }
          if(top->right){
               parent[top->right]=top;
              q.push(top->right);
             
          }
      }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
       unordered_map<TreeNode* ,TreeNode* >parent;
       setparent(root,parent,target);
       
       unordered_map<TreeNode*,bool>visited;
       queue<TreeNode*>q;
       q.push(target);
       visited[target]=true;

       int currlevel=0;
       while(!q.empty()){

       int siz=q.size();
       if(currlevel++ == k)break;

       for(int i=0;i<siz;i++){
        TreeNode* top=q.front();
        q.pop();

        if(top->left && visited[top->left]==false){
            q.push(top->left);
            visited[top->left]=true;
        }
        if(top->right && visited[top->right]==false){
            q.push(top->right);
            visited[top->right]=true;
        }

        //storing final ans in queue

        if(parent[top] &&visited[parent[top]]==false){
            q.push(parent[top]);
            visited[parent[top]]=true;
         }
        }
       }

        vector<int>ress;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ress.push_back(node->val);
        }
        return ress;

    }
};