#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    for (char c : s) {
        auto inerator = m.find(c);
        if (inerator != m.end()) {
            m[c]++;
        } else {
            m[c] = 1;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (m[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}