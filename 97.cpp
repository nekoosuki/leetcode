#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        auto dp = vector<vector<int>>(n+1,vector<int>(m+1,false));
        if (n + m != t) {
            return false;
        }
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[k]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[k]);
                }
            }
        }
        return dp[n][m];
    }
};