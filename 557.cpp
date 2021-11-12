#include <iostream>
using namespace std;
class Solution {
   public:
    string reverseWords(string s) {
        int pre_i = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ' ') {
                // reverse(s.begin()+pre_i, s.begin()+i);
                int p = pre_i, q = i - 1;
                while (p < q) {
                    char t = s[p];
                    s[p] = s[q];
                    s[q] = t;
                    p++;
                    q--;
                }
                pre_i = i + 1;
            }
        }
        // reverse(s.begin()+pre_i, s.end());
        int p = pre_i, q = s.size() - 1;
        while (p < q) {
            char t = s[p];
            s[p] = s[q];
            s[q] = t;
            p++;
            q--;
        }
        return s;
    }
};