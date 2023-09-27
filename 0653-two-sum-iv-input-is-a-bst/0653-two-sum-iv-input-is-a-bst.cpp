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

class BSTiterator{
    private:
    stack<TreeNode*> st;
    bool reverse = true;
    public:
    BSTiterator(TreeNode* root,bool flag){
        reverse = flag;
        pushAll(root);
    }
    
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        
        if(reverse){
            pushAll(temp->left);
        }
        else{
            pushAll(temp->right);
        }
        
        return temp->val;
    }
    
    bool hasNext(){
        return !st.empty();
    }
    
    void pushAll(TreeNode* root){
        // while root not equal to null
        while(root){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // base case
        if(root == NULL){
            return false;
        }
        
        // Creating the BSTiterator
        BSTiterator left(root,false);
        BSTiterator right(root,true);
        
        int i = left.next();
        int j = right.next();
        //cout<<i<<" "<<j<<endl;
        while(i < j){
            if(i + j == k){
                return true;
            }
            else if(i + j < k){
                i = left.next();
            }
            else{
                j = right.next();
            }
        }
        
        return false;
    }
};