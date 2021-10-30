#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* newh = head->next;
        head->next = swapPairs(newh->next);
        newh->next = head;
        return newh;
    }
};