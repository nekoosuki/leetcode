#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i=0,j=0;
        int maxlen=0;
        while(j<s.size()){
            char c = s[j];
            if(m.find(c)!=m.end()){
                maxlen = max(maxlen, j-i);
                i = max(i,m[c]+1);
            }
            m[c] = j++;
        }
        maxlen = max(maxlen, j-i);
        return maxlen;
    }
};