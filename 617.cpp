struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if(root1==nullptr&&root2==nullptr)return nullptr;
        int v1 = root1==nullptr?0:root1->val;
        int v2 = root2==nullptr?0:root2->val;
        TreeNode* root = new TreeNode(v1+v2);
        if(root1&&!root2){
            root->left = mergeTrees(root1->left,nullptr);
            root->right = mergeTrees(root1->right,nullptr);
        }
        if(!root1&&root2){
            root->left = mergeTrees(nullptr, root2->left);
            root->right = mergeTrees(nullptr, root2->right);
        }
        if(root1&&root2){
            root->left = mergeTrees(root1->left,root2->left);
            root->right = mergeTrees(root1->right, root2->right);
        }
        return root;
    }
};