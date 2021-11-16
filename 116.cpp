#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        queue<Node*> q;
        Node* pre = NULL;
        int layer = 1;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            if (q.front()->left) {
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                q.push(q.front()->right);
            }
            pre = q.front();
            q.pop();
            if (q.empty() || pow(2,layer) == q.size()) {
                pre->next = NULL;
                layer++;
            } else {
                pre->next = q.front();
            }
        }
        return root;
    }
};