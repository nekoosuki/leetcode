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
    vector<vector<int>> res;
    void dfs(TreeNode* root,vector<int> &tmp,int sum){
        if(!root) return ;
        tmp.push_back(root->val);
        if(root->val==sum&&!root->left&&!root->right){
            res.push_back(tmp);
        }
        dfs(root->left,tmp,sum-root->val);
        dfs(root->right,tmp,sum-root->val);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        dfs(root,tmp,targetSum);
        return res;
    }
};