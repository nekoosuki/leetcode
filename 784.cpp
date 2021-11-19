#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> res;
    void helper(string s, int start){
        while(start!=s.size()){
            char c = s[start];
            if(c >= '0' && c <= '9'){
                start++;
            }else{
                helper(s, start+1);
                if(c >= 'a' && c <= 'z'){
                    s[start] = c-32;
                }else{
                    s[start] = c+32;
                }
                res.push_back(s);
                helper(s, start+1);
                return;
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        res.push_back(s);
        helper(s, 0);
        return res;
    }
};