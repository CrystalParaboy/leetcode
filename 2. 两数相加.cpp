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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* cur = head;
        int more = 0;
        while(l1 || l2 ){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + more;
            if(!head) head = cur = new ListNode(sum%10);
            else{
                cur->next = new ListNode(sum%10);
                cur = cur->next;
            }
            if(sum >= 10)  more = 1;
            else more = 0;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(more == 1) cur->next = new ListNode(1);
        return head;
    }
};
