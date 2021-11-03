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
#include <vector>

using namespace std;

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(-100001);
        dummy->left = root;
        TreeNode* pre = dummy;
        TreeNode* cur = root;
        for (;;) {
            if (!cur) break;
            if (cur->val < key) {
                pre = cur;
                cur = cur->right;
            } else if (cur->val > key) {
                pre = cur;
                cur = cur->left;
            } else {
                if (pre->left == cur) {
                    TreeNode* tmp = cur->left;
                    pre->left = cur->right;
                    cur = cur->right;
                    while (cur && cur->left) cur = cur->left;
                    if (cur)
                        cur->left = tmp;
                    else
                        pre->left = tmp;
                } else if (pre->right == cur) {
                    TreeNode* tmp = cur->right;
                    pre->right = cur->left;
                    cur = cur->left;
                    while (cur && cur->right) cur = cur->right;
                    if (cur)
                        cur->right = tmp;
                    else
                        pre->right = tmp;
                }
                break;
            }
        }
        return dummy->left;
    }
};