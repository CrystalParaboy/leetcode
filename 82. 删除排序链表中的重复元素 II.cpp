
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || !head->next) return head;
        ListNode* temp = new ListNode(0, head);
        ListNode* left, *right;
        ListNode* cur = temp;
        while(cur->next){
            left = cur->next;
            right = left;
            while(right->next && right->next->val == left->val) right = right->next;      
            if(right == left) cur = cur->next;
            else cur->next = right->next;
        }
        return temp->next;
    }
};
