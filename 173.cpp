struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};
class BSTIterator {
   private:
    TreeNode* listroot = nullptr;
    void genlist(TreeNode* node) {
        if (node->right) genlist(node->right);
        node->right = listroot;
        listroot = node;
        if (node->left) genlist(node->left);
    }

   public:
    BSTIterator(TreeNode* root) {
        genlist(root);
    }

    int next() {
        int r = listroot->val;
        listroot=listroot->right;
        return r;
    }

    bool hasNext() {
        return listroot;
    }
};