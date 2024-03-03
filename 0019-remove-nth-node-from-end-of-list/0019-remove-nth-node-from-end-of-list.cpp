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
    
     int getLength(ListNode*head) {
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
}
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        
        int size=getLength(head);

        if(head->next==NULL && n==1)return NULL;
        
        if(size==n) return head -> next;
        
          ListNode *curr=head;
          ListNode *temp=head;

        for(int i=0;i<=size-n-1;i++){
            curr=curr->next;
        }
         for(int i=0;i<size-n-1;i++){
            temp=temp->next;
        }
        temp->next=curr->next;
        curr->next=NULL;
        
        return head;
    }
};