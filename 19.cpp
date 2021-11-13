struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p=dummy,*q=dummy;
        for(int i=0;i<=n;i++){
            q=q->next;
        }
        while(q){
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return dummy->next;
    }
};