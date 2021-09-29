#include <iostream>

using namespace std;

int longestPalindromeSubseq(string s) {
    int l = s.size();
    int dp[l][l];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < l; i++) {
        dp[i][i] = 1;
    }
    for (int i = l - 2; i >= 0; i--) {
        for (int j = i + 1; j < l; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][l - 1];
}
