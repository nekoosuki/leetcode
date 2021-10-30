#include <iostream>
class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

   private:
    ListNode* head;
    int len;

   public:
    MyLinkedList() {
        head = nullptr;
        len = 0;
    }

    int get(int index) {
        if (index >= len || index < 0) return -1;
        ListNode* tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void addAtHead(int val) {
        ListNode* newh = new ListNode(val);
        newh->next = head;
        head = newh;
        len++;
    }

    void addAtTail(int val) {
        if (!head) {
            addAtHead(val);
        } else {
            ListNode* tmp = head;
            while (tmp->next) tmp = tmp->next;
            ListNode* newnode = new ListNode(val);
            tmp->next = newnode;
            len++;
        }
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
        } else if (index > len) {
            return;
        } else {
            ListNode* tmp = head;
            ListNode* newnode = new ListNode(val);
            for (int i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            newnode->next = tmp->next;
            tmp->next = newnode;
            len++;
        }
    }

    void deleteAtIndex(int index) {
        if (index == 0) {
            head = head->next;
            len--;
        } else if (index < 0 || index >= len) {
            return;
        } else {
            ListNode* tmp = head;
            for (int i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
            len--;
        }
    }
};