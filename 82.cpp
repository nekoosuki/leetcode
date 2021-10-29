#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* root = new ListNode(-101);
        root->next = head;
        ListNode *p = root, *q=p->next;
        while(q&&q->next){
            if(q->val!=q->next->val){
                p=q;
                q=q->next;
            }else{
                while(q->next && q->val==q->next->val){
                    q=q->next;
                }
                q=q->next;
                p->next=q;
            }
        }
        return root->next;
    }
};