#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//KMP算法
//简   单
    void buildNext(string& pattern, vector<int>& nxt){
        nxt[0] = -1;
        int j=0,k=-1;
        while(j<pattern.length()){
            if(k==-1||pattern[j]==pattern[k]){
                nxt[++j] = ++k;
            }else{
                k=nxt[k];
            }
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.length()==0)return 0;
        int i=0,j=0;
        vector<int> nxt(needle.length()+1);
        buildNext(needle,nxt);
        while(i<haystack.length()){
            if(j==-1||haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j=nxt[j];
            }
            if(j==needle.length())return i-j;
        }
        return -1;
    }
};

