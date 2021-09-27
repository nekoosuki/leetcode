#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    //数字太大了报错 还以为是没初始化
    unsigned int dp[row][col];
    if (obstacleGrid[row - 1][col - 1] == 1) {
        return 0;
    } else {
        dp[row - 1][col - 1] = 1;
    }
    for (int i = row - 2; i >= 0; i--) {
        if (obstacleGrid[i][col - 1] == 1) {
            dp[i][col - 1] = 0;
        } else {
            dp[i][col - 1] = dp[i + 1][col - 1];
        }
    }
    for (int i = col - 2; i >= 0; i--) {
        if (obstacleGrid[row - 1][i] == 1) {
            dp[row - 1][i] = 0;
        } else {
            dp[row - 1][i] = dp[row - 1][i + 1];
        }
    }
    for (int i = row - 2; i >= 0; i--) {
        for (int j = col - 2; j >= 0; j--) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
    }
    return dp[0][0];
}

int main(int argc, char const* argv[]) {
    vector<vector<int>> v = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0},{0,1,0}};
    cout << uniquePathsWithObstacles(v) << endl;
    return 0;
}
