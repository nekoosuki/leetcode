#include <cstring>
#include <iostream>
#include <string>

using namespace std;
string longestPalindrome(string s) {
    int i;
    int l = s.length();
    int max = 1;
    int start = 0;
    bool flag = false;
    for (i = 0; i < l; i++) {
        int si = i, sj = i;
        while (s[si] == s[sj]) {
            if (sj - si + 1 > max) {
                max = sj - si + 1;
                start = si;
            }
            si--;
            sj++;
            if (si < 0 || sj >= l) {
                break;
            }
        }
    }
    return s.substr(start, max);
}

int main(int argc, char const *argv[]) {
    string res = longestPalindrome("ab");
    cout << res << endl;
    return 0;
}
