
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        fast = reverse(fast);
        merge(head, fast);
        return;
    }

    ListNode* reverse(ListNode* head){
        if(!head) return nullptr;
        ListNode* cur = head->next;
        if(!cur) return head;
        ListNode* pre = head;
        head->next = nullptr;
        ListNode* nex;
        while(cur){
            nex = cur->next;
            cur->next=pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }

    void merge(ListNode* l1, ListNode* l2) {
        ListNode* temp1;
        ListNode* temp2;
        while (l1 != nullptr && l2 != nullptr) {
            temp1 = l1->next;
            temp2 = l2->next;
            
            l1->next = l2;
            l1 = temp1;

            l2->next = l1;
            l2 = temp2;
        }
    }

};
