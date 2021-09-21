#include <iostream>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    bool canBreak[s.size() + 1];
    for (int i = 0; i <= s.size(); i++) {
        canBreak[i] = false;
    }
    canBreak[0] = true;
    for (int i = 0; i < s.size(); i++) {
        if (!canBreak[i]) {
            continue;
        }
        for (int j = i + 1; j <= s.size(); j++) {
            if (canBreak[j]) {
                continue;
            }
            string str = s.substr(i, j-i);
            for (string w : wordDict) {
                if (str == w) {
                    canBreak[j] = true;
                    break;
                }
            }
        }
    }
    return canBreak[s.size()];
}

int main(int argc, char const* argv[]) {
    vector<string> v = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak("catsandog", v) << endl;
    return 0;
}
