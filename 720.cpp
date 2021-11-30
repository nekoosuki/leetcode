#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    // 排序算法
    // static bool lcomp(string& a, string& b){
    //     if(a.length()>b.length()){
    //         return false;
    //     }else if(a.length()<b.length()){
    //         return true;
    //     }else{
    //         for(int i=0;i<a.length();i++){
    //             if(a[i]>b[i]){
    //                 return false;
    //             }else if(a[i]<b[i]){
    //                 return true;
    //             }
    //         }
    //         return true;
    //     }
    // }
    // string longestWord(vector<string>& words) {
    //     unordered_set<string> set;
    //     sort(words.begin(), words.end(), lcomp);
    //     string res = "";
    //     for(string s:words){
    //         if(s.length()==1||set.find(s.substr(0,s.length()-1))!=set.end()){
    //             res = s.length()>res.length()?s:res;
    //             set.emplace(s);
    //         }
    //     }
    //     return res;
    // }

    //前缀树，字典树
    struct TrieNode {
        bool isword;
        vector<TrieNode *> children;
        TrieNode() : isword(false), children(26, nullptr) {}
    };
    TrieNode *root = nullptr;
    string res = "";
    void add(string &word) {
        TrieNode *cur = root;
        for (char ch : word) {
            if (cur->children[ch - 'a'] == nullptr) {
                cur->children[ch - 'a'] = new TrieNode();
            }
            cur = cur->children[ch - 'a'];
        }
        cur->isword = true;
    }
    void findl(TrieNode *root, string &tmp) {
        if (root) {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != nullptr && root->children[i]->isword) {
                    string t = tmp + char('a' + i);
                    if (t.length() > res.length()) res = t;
                    findl(root->children[i], t);
                }
            }
        }
    }
    string longestWord(vector<string> &words) {
        root = new TrieNode();
        for (string word : words) {
            add(word);
        }
        string t = "";
        findl(root, t);
        return res;
    }
};