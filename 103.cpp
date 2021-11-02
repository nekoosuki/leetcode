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
#include <queue>
#include <deque>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> res;
        deque<int> dq;
        bool order = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int nodes = q.size();
            for(int i=0;i<nodes;i++){
                TreeNode* node = q.front();
                q.pop();
                if(order){
                    dq.push_back(node->val);
                }else{
                    dq.push_front(node->val);
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(vector<int>(dq.begin(),dq.end()));
            dq.clear();
            order=!order;
        }
        return res;
    }
};