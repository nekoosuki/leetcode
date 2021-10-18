struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <vector>

using namespace std;


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!(root->left||root->right)||!root){
            return false;
        }
        vector<int> res;
        traversal(root, res);
        int i=0,j=res.size()-1;
        do{
            int p=res[i],q=res[j];
            if(p+q==k){
                return true;
            }else if(p+q<k){
                i++;
            }else{
                j--;
            }
        }while(i!=j);
        return false;
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