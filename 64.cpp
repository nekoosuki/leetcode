#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (m == 1) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += grid[0][i];
        }
        return sum;
    } else if (n == 1) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += grid[i][0];
        }
        return sum;
    }
    int path[m][n];
    path[m - 1][n - 1] = grid[m - 1][n - 1];
    for (int i = m - 2; i >= 0; i--) {
        path[i][n - 1] = grid[i][n - 1] + path[i + 1][n - 1];
    }
    for (int j = n - 2; j >= 0; j--) {
        path[m - 1][j] = grid[m - 1][j] + path[m - 1][j + 1];
    }

    int p = 1;
    int th = max(m, n);
    while (true) {
        if (p <= n - 1)
            for (int i = m - 1 - p; i >= 0; i--) {
                path[i][n - p - 1] =
                    min(path[i + 1][n - p - 1], path[i][n - p]) +
                    grid[i][n - p - 1];
            }
        if (p <= m - 1)
            for (int i = n - 1 - p; i >= 0; i--) {
                path[m - p - 1][i] =
                    min(path[m - p - 1][i + 1], path[m - p][i]) +
                    grid[m - p - 1][i];
            }
        if (++p == th) {
            break;
        }
    }
    return path[0][0];
}

int main(int argc, char const* argv[]) {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    vector<vector<int>> v = {v1, v2};
    cout << minPathSum(v) << endl;
    return 0;
}
