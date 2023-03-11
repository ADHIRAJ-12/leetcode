/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
         if(!head)           //head null to return null
            return NULL;
        if(!head->next)
        {
            return new TreeNode(head->val);             //head ka next ni hai to new node =head bana k dedo
        }
        ListNode *slow=head,*fast=head->next;            
        while(fast->next&&fast->next->next)                     //finding middle by slow and fast pointers concept
        {  
            slow=slow->next;
            fast=fast->next->next;
            
        }
        ListNode *mid=slow->next;                          
        slow->next=NULL;
        
        TreeNode *root=new TreeNode(mid->val);                //mid = root node for our tree 
        root->left=sortedListToBST(head);                     // left part of root if from head to mid
        root->right=sortedListToBST(mid->next);              // right part of our tree id from mid+1 to end
        return root;
        
        
        
        
        
        
    }
};