
// Definition for singly-linked list.
#include <limits.h>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        ListNode* head = new ListNode();
        ListNode* res = head;
        if(l1->val < l2->val){
            head->val = l1->val;
            l1 = l1->next;
        }else{
            head->val = l2->val;
            l2 = l2->next;
        }
        while(l1 && l2){
            if (l1->val < l2->val){
                head->next = new ListNode(l1->val);
                head = head->next;
                l1 = l1->next;
            }else{
                head->next = new ListNode(l2->val);
                head = head->next;
                l2 = l2->next;
            }
        }
        if(!l1){
            head->next = l2;
        }
        if(!l2){
            head->next = l1;
        }
        return res;
    }
};