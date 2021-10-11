// Definition for singly-linked list.
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        while (head = head->next) {
            if (head->val == 100001) {
                return true;
            } else {
                head->val = 100001;
            }
        }
        return false;
    }
};