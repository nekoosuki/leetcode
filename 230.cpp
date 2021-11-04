struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root|| s.size() > 0) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) break;
            root = root->right;
        }
        return root->val;
    }
};
