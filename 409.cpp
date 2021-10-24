#include <unordered_map>
using namespace std;
class Solution {
   public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int res = 0;
        bool odd = false;
        for (char c : s) m[c]++;
        for (auto it = m.begin(); it != m.end(); it++) {
            res += it->second / 2 * 2;
            if (!odd && it->second % 2) {
                res += 1;
                odd = true;
            }
        }
        return res;
    }
};