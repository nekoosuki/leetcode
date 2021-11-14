#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        unordered_map<char,int> m;
        for (int i = 0; i < s1.size(); ++i) {
            m[s1[i]]--;
            m[s2[i]]++;
        }
        int diff = 0;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second)diff++;
        }
        if (diff == 0) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            char left = s2[i-s1.size()], right = s2[i];
            if (left == right) {
                continue;
            }
            if (m[right] == 0) {
                ++diff;
            }
            if (++m[right] == 0) {
                --diff;
            }
            if (m[left] == 0) {
                ++diff;
            }
            if (--m[left] == 0) {
                --diff;
            }
            if (diff == 0) {
                return true;
            }
        }
        return false;
    }
};