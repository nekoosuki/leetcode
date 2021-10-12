
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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* rev = head->next;
        if(!rev){
            return head;
        }
        ListNode* rev_n = rev->next;
        head->next = nullptr;
        while(rev_n){
            rev->next = head;
            head = rev;
            rev = rev_n;
            rev_n = rev_n->next;
        }
        rev->next = head;
        return rev;
    }
};