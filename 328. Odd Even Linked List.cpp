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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr||head->next->next==nullptr) return head;
        int i=1;
        ListNode* begin;
        ListNode* end;
        ListNode* temp;
        while(1){
            
            if(i==1){
                temp=head->next;
                begin=temp->next;
                head->next=begin;
                temp->next=begin->next;   
                begin->next=temp;
                if(temp->next==nullptr||temp->next->next==nullptr) break;   
                end=temp;                     
            }
            else{
                end=end->next;
                begin->next=end->next;
                begin=begin->next;
                end->next=end->next->next;
                begin->next=temp;
                if(end->next==nullptr||end->next->next==nullptr) break;

            }
            cout<<"temp val: "<<temp->val<<endl;
            cout<<"begin val: "<<begin->val<<endl;
            cout<<"end val: "<<end->val<<endl;
            i++;
        }
        return head;
        
    }
};
/**
1 2 3 4 5 6 7 8
1 3 2 4 5 6 7 8
  b t e
1 3 5 2 4 6 7 8
    b t e  
1 3 5 7 2 4 6 8
**/ 
