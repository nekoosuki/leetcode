#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    //边界处理绕晕了
    vector<vector<int>> res(mat);
    int row = mat.size(), col = mat[0].size();
    int dp[row + 1][col + 1];
    for (int i = 0; i <= row; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= col; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] +
                       mat[i - 1][j - 1];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int xmin = max(i - k, 0);
            int ymin = max(j - k, 0);
            int xmax = min(i + k, row - 1);
            int ymax = min(j + k, col - 1);
            res[i][j] = dp[xmax + 1][ymax + 1] - dp[xmin][ymax + 1] -
                        dp[xmax + 1][ymin] + dp[xmin][ymin];
        }
    }
    return res;
}