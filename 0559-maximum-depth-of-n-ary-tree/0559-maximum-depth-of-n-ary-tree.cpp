/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        
         if(!root) return 0;
        queue<Node*> q;
        int depth=0;
        q.push(root);
        while(!q.empty()){
            depth++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* temp=q.front();
                q.pop();
                for(auto it:temp->children){
                    q.push(it);
                }
            }
        }
        return depth;
        
    }
};