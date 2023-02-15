/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* fast= head;
        ListNode* low = head;
        bool begin = 0;
        while(fast && (fast != low || begin == 0)){
            begin = 1;
            fast = fast->next;
            if(fast && fast->next) fast = fast->next;
            else return nullptr;
            low = low->next;
        }
        fast = head;
        while(fast != low){
            fast = fast->next;
            low = low->next;
        }
        return fast;
    }
};
