#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        ListNode *p = head, *q = head->next;
        while (q) {
            if (p->val == val) {
                ListNode* tmp = p;
                p = q;
                head = p;
                q = q->next;
                delete tmp;
            } else if (q->val == val) {
                ListNode* tmp = q;
                q = q->next;
                p->next = q;
                delete tmp;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        if(p->val == val){
            return nullptr;
        }
        return head;
    }
};