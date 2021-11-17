/*给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是
mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。*/

#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    //一个超时用例
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = bfs(mat, i, j);
            }
        }
        return res;
    }
    int bfs(vector<vector<int>>& mat, int i, int j) {
        int m = mat.size(), n = mat[0].size();
        // vector<vector<bool>> seen(m, vector<bool>(n));
        bool seen[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                seen[i][j]=false;
            }
        }
        if (mat[i][j] == 0) return 0;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        seen[i][j]=true;
        int count = 0, x = 0, pre_x = 1;
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            if (mat[r][c] == 0) return count;
            if (r > 0 && !seen[r-1][c]) {
                q.push(make_pair(r - 1, c));
                seen[r-1][c]=true;
                x++;
            }
            if (r < m - 1 && !seen[r+1][c]) {
                q.push(make_pair(r + 1, c));
                seen[r+1][c]=true;
                x++;
            }
            if (c > 0 && !seen[r][c-1]) {
                q.push(make_pair(r, c - 1));
                seen[r][c-1]=true;
                x++;
            }
            if (c < n - 1 && !seen[r][c+1]) {
                q.push(make_pair(r, c + 1));
                seen[r][c+1]=true;
                x++;
            }
            if (--pre_x==0) {
                pre_x = x;
                x = 0;
                count++;
            }
            q.pop();
        }
        return count;
    }
};