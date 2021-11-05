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
#include <queue>
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        ser_helper(root, ret);
        return ret;
    }


    void ser_helper(TreeNode* root, string& str) {
        if (!root) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            ser_helper(root->left, str);
            ser_helper(root->right, str);
        }
    }



    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string buff;
        for(char c:data){
            if(c==','){
                q.push(buff);
                buff="";
            }else{
                buff.push_back(c);
            }
        }
        return de_helper(q);
    }


    TreeNode* de_helper(queue<string>& data){
        if(data.empty())return nullptr;
        if(data.front() == "None"){
            data.pop();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(data.front()));
        data.pop();
        root->left = de_helper(data);
        root->right = de_helper(data);
        return root;
    }
};