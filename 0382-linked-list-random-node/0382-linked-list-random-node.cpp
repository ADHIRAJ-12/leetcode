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
    
    ListNode *head;
    
    Solution(ListNode* head) {
       this->head=head; 
    }
    
    int getRandom() {
        
        int node=0;
        int ans=0;
        
        ListNode *curr=head;
        while(curr){
            
            node++;
            if(rand()%node==0)ans=curr->val;
            
            curr=curr->next;
            
        }
        return ans;
        
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */