#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = l1->val;
        l1 = l1->next;
        int b = l2->val;
        l2 = l2->next;
        ListNode* root = new ListNode((a + b) % 10);
        ListNode* cur = root;
        int carry = (a + b) / 10;
        while (l1 || l2 || carry) {
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            } else {
                a = 0;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            } else {
                b = 0;
            }
            cur->next = new ListNode((a + b + carry) % 10);
            cur = cur->next;
            carry = ((a + b + carry) / 10);
        }
        return root;
    }
};