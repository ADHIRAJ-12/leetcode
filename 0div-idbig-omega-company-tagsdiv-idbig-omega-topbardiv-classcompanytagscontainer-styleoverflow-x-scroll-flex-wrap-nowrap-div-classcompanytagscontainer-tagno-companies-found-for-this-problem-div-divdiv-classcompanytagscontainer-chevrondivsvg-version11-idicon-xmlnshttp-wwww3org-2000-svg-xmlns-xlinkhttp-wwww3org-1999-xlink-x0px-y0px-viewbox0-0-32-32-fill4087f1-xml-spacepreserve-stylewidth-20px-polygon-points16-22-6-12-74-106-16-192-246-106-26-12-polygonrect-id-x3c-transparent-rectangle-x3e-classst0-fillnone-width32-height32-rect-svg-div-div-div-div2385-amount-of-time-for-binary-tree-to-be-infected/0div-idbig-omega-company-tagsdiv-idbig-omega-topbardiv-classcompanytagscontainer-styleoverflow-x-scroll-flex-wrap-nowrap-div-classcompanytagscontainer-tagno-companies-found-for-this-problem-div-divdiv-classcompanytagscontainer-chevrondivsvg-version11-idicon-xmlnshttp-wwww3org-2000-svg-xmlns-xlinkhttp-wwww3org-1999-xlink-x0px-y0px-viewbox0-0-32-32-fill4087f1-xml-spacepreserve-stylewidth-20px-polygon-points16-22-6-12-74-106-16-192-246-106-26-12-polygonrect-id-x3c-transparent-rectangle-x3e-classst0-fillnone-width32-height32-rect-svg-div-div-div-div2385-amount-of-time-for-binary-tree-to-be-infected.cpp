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
    
    void find(TreeNode* root,int target,TreeNode* &ans)
{
    if(root==NULL)return ;
    if (root->val == target) {
         ans = root;
         return;
    }
    find(root->left,target,ans);
    find(root->right,target,ans);
}
    
    int amountOfTime(TreeNode* root, int start) {
        
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
    TreeNode* tar;
    find(root,start,tar);
    map<TreeNode*,int>vis;

    queue<TreeNode*>qu;
    qu.push(tar);
    vis[tar]=1;
    int dis=0;

    while(!qu.empty()){

        int siz=qu.size();
        int flag=0;
         for(int i=0;i<siz;i++){
             
             TreeNode* node=qu.front();
             qu.pop();
            if (parent[node] && !vis[parent[node]]) {
                flag=1;
                vis[parent[node]]=1;
                qu.push(parent[node]);
            }
            if (node->left && !vis[node->left]) {
                 flag=1;
                vis[node->left]=1;
                qu.push(node->left);
            }
            if(node->right && !vis[node->right]){
                    flag=1;
                    vis[node->right]=1;
                    qu.push(node->right);
                    
            }
         

       }
        if(flag)dis++;

    }
    return dis;
        
    }
};