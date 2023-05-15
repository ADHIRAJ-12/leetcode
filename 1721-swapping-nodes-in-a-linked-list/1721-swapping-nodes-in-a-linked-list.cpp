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
class Solution {
public:
      
//using slow and fadt pointers
    
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* curr=head;
        for(int i=1;i<k;i++) 
            curr=curr->next;
        
        ListNode *slow=head,*fast=curr->next;
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        swap(slow->val,curr->val);
        return head;
    }
};