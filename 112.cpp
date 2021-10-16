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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return pathSum(root, targetSum, 0);
    }
    bool pathSum(TreeNode* root, int targetSum, int currSum){
        if(!root){
            return false;
        }
        if(currSum+root->val == targetSum &&!root->left&&!root->right){
            return true;
        }
        return pathSum(root->left, targetSum, currSum+root->val)||pathSum(root->right, targetSum, currSum+root->val);
    }
};