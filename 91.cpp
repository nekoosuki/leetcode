#include <iostream>

using namespace std;

int numDecodings(string s) {
    //很多奇奇怪怪的情况 边界值处理
    if (s == "0") {
        return 0;
    }
    int l = s.size();
    int dp[l];
    dp[l - 1] = s[l - 1] == '0' ? 0 : 1;
    if (l == 1) {
        return 1;
    }
    if (s[l - 1] == '0') {
        if (s[l - 2] == '1' || s[l - 2] == '2') {
            dp[l - 2] = 1;
        } else {
            dp[l - 2] = 0;
        }
    } else if (s[l - 2] == '1' ||
               (s[l - 2] == '2' && '0' <= s[l - 1] && s[l - 1] <= '6')) {
        dp[l - 2] = 2;
    } else if (s[l - 2] == '0') {
        dp[l - 2] = 0;
    } else {
        dp[l - 2] = 1;
    }
    if (l == 2) {
        return dp[l - 2];
    }
    
    for (int i = l - 3; i >= 0; i--) {
        if (s[i + 1] == '0') {
            if (s[i] == '1' || s[i] == '2') {
                dp[i] = dp[i + 2];
            } else {
                dp[i] = 0;
            }
        } else if (s[i] == '1') {
            dp[i] = dp[i + 1] + dp[i + 2];
        } else if (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6') {
            dp[i] = dp[i + 1] + dp[i + 2];
        } else if (s[i] == '0') {
            dp[i] = 0;
        } else {
            dp[i] = dp[i + 1];
        }
    }
    return dp[0];
}

int main(int argc, char const *argv[]) {
    string s = "100";
    cout << numDecodings(s) << endl;
    return 0;
}
