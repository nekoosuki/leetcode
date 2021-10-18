struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValidBST(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        long long last = INT64_MIN;
        for(int e:res){
            if(e > last){
                last=e;
            }else{
                return false;
            }
        }
        return true;
    }
    void traversal(TreeNode *root, vector<int> &vec) {
        if (root == NULL) {
            return;
        }
        traversal(root->left, vec);
        vec.push_back(root->val);
        traversal(root->right, vec);
    }
};