class Solution {
public:
    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;
        auto fast = head;
        auto slow = head;
        auto b = head;
        while(fast && fast->next){
            fast = fast->next->next;
            b = slow;
            slow = slow->next;
        }
        b->next = nullptr;
        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(slow);
        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
