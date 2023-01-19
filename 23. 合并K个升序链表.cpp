
class Solution {
public:
    struct comb{
        int val;
        ListNode* p;
        bool operator < (const comb & other) const{
            return val < other.val;
        }
    };

    multiset<comb> com_set;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto i:lists){
            if(i) com_set.insert({i->val,i});
        }
        /**
        for(auto i:com_set){
            cout<<i.val<<' ';
        }
        **/
        ListNode head;
        ListNode* cur = &head;
        while(!com_set.empty()){
            auto fir = com_set.begin();
            //cout<<fir->val<<' ';
            cur->next = fir->p;
            cur = cur->next;
            if(fir->p->next) com_set.insert({fir->p->next->val, fir->p->next});
            com_set.erase(fir);
        }
        return head.next;

    }
};
