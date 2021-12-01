#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//KMP的三分之二
//困   难
    string longestPrefix(string s) {
        vector<int> nxt(s.length()+1);
        nxt[0] = -1;
        int j=0,k=-1;
        while(j<s.length()){
            if(k==-1||s[j]==s[k]){
                nxt[++j] = ++k;
            }else{
                k=nxt[k];
            }
        }
        return s.substr(0,nxt[s.length()]);
    }
};