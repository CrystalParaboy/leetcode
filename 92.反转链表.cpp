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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* begin = new ListNode(0, head);
        auto fir = begin;
        auto res = begin;
        while(left>0){
            begin = begin->next;
            if(left>1) fir = fir->next;
            --left;
            --right;
        }
        //cout<< begin->val <<' '<<fir->val;
        
        ListNode* temp;
        ListNode* pre;
        ListNode* end = fir->next;
        while(right>=0){
            temp = begin->next;
            begin->next = pre;
            pre = begin;
            begin = temp;
            --right;
        }
        end->next = begin;
        fir->next = pre;
        return res->next;
    }
};

/**
    right = 2
**/
