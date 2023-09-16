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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            
    unordered_map<TreeNode*,TreeNode*>parent;
    queue<TreeNode*>q;
    q.push(root);
    // parent[root]=NULL;

    while(!q.empty()){

        TreeNode*node=q.front();
        q.pop();

        if(node->left){
            parent[node->left]=node;
            q.push(node->left);
        }

        if(node->right){
            parent[node->right]=node;
            q.push(node->right);
        }

    }
    
    //parent is set for each node now
    unordered_map<TreeNode*,bool>vis;
    queue<TreeNode*>qu;
    qu.push(target);
    vis[target]=true;
    int dis=0;
    while(!qu.empty()){
        int siz=qu.size();
         if(dis++ ==k)break;
         for(int i=0;i<siz;i++){
             TreeNode* node=qu.front();
        qu.pop();
        vis[node]=1;
        if (parent[node] && !vis[parent[node]]) {
            qu.push(parent[node]);
            vis[parent[node]]=1;
        
        }
        if (node->left && !vis[node->left]) {
            qu.push(node->left);
            vis[node->left]=1;
        }
        if(node->right && !vis[node->right]){
                qu.push(node->right);
                 vis[node->right]=1;
        }

     }
       

    }
   vector<int>vec;
   while(!qu.empty()){
       vec.push_back(qu.front()->val);
       qu.pop();
   }
   return vec;
        
    }
};