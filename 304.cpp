#include <iostream>
#include <vector>

using namespace std;

//和1314一样

class NumMatrix {
   public:
    vector<vector<int>> dp;
    int row, col;
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        dp.resize(row + 1, vector<int>(col + 1));
        for (int i = 0; i <= row; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= col; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] +
                           matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};