struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

#include <stack>

using namespace std;


class Solution {
public:
    bool path(TreeNode* root, TreeNode* node, stack<TreeNode*>& s){
        if(!root||!node)return false;
        s.push(root);
        if(root==node)return true;
        bool found = false;
        if(root->left){
            found = path(root->left, node, s);
        }
        if(!found && root->right){
            found = path(root->right, node, s);
        }
        if(!found)s.pop();
        return found;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1, s2;
        path(root, p, s1);
        path(root, q, s2);
        do{
            s1.size()<s2.size()?s2.pop():s1.pop();
        }while(s1.top()->val!=s2.top()->val);
        return s1.top();
    }
};