#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* cur = head;
        while(cur){
            m[cur] = new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur){
            m[cur]->next = m[cur->next];
            m[cur]->random = cur->random?m[cur->random]:nullptr;
            cur=cur->next;
        }
        return m[head];
    }
};
