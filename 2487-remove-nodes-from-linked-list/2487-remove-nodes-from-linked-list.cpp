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
    ListNode* removeNodes(ListNode* head) {
        
        stack<int>s;
        ListNode *temp=head;
        
        while(temp){
            
       while(!s.empty() && temp->val>s.top())s.pop(); 
            s.push(temp->val);
            temp=temp->next;
            
            
        }
        vector<int>vec;
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
        reverse(vec.begin(),vec.end());
       
        if(vec.size()==0)return NULL;
        
        ListNode* res=new ListNode(vec[0]);
        temp=res;
        for(int i=1;i<vec.size();i++){
            res->next=new ListNode(vec[i]);
            res=res->next;
        }
        return temp;
        
    }
};