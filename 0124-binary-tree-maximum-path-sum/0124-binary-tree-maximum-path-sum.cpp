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
    
        int maxPath(TreeNode* node, int &maxi){
            if(node==NULL) return 0;
            
            int left=max(0,maxPath(node->left,maxi));
            int right=max(0,maxPath(node->right,maxi));

            maxi=max(maxi,left+right+node->val);
            return max(left,right)+node->val;
        }
    
            int maxPathSum(TreeNode* root) {
            int maxi=INT_MIN;
            
            maxPath(root,maxi);
            return maxi;
        }
};

// /     void solve(TreeNode* root, int sum, int &maxSum, int len, int &maxLen) {
//         //base case
//         if( root == NULL ) {
            
//             if(len > maxLen) 
//             {
//                 maxLen = len;
//                 maxSum = sum;
//             }
//             else if(len == maxLen) 
//             {
//                 maxSum = max(sum, maxSum);
//             }
//             return;
//         }
        
//         sum = sum + root->val;
        
//         solve(root->left, sum, maxSum, len+1, maxLen);
//         solve(root->right, sum, maxSum, len+1, maxLen);

//     }
 
    // int maxPathSum(TreeNode* root) {
     
//         int len = 0;
//         int maxLen = 0;
        
//         int sum = 0;
//         int maxSum = INT_MIN;
        
//         solve(root, sum, maxSum, len, maxLen);
        
//         return maxSum;   
    // }
// };
    