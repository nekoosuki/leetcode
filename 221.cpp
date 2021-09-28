#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    //数学题
    int row = matrix.size();
    int col = matrix[0].size();
    int maxl = 0;
    int dp[row][col];
    for (int i = 0; i < row; i++) {
        dp[i][0] = matrix[i][0] == '0' ? 0 : 1;
        maxl = max(maxl, dp[i][0]);
    }
    for (int i = 0; i < col; i++) {
        dp[0][i] = matrix[0][i] == '0' ? 0 : 1;
        maxl = max(maxl, dp[0][i]);
    }
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] =
                    min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                maxl = max(maxl, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return maxl * maxl;
}
