/*
在给定的网格中，每个单元格可以有以下三个值之一：

    值 0 代表空单元格；
    值 1 代表新鲜橘子；
    值 2 代表腐烂的橘子。

每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
*/
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
   private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int prero = 0, good=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    prero++;
                }
                if (grid[i][j] == 1){
                    good++;
                }
            }
        }
        if(!prero&&!good)return 0;
        if(!prero&&good)return -1;
        int minutes = 0;
        int newro = 0;
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            for(auto shift:dirs){
                int x = i+shift[0], y = j+shift[1];
                if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1){
                    grid[x][y]=2;
                    q.push(make_pair(x,y));
                    newro++;
                    good--;
                    cout<<newro<<endl;
                }
            }
            if(--prero==0){
                if(!newro){
                    if(good){
                        return -1;
                    }else{
                        return minutes;
                    }
                }
                minutes++;
                prero=newro;
                newro=0;
            }
            q.pop();
        }
        return minutes;
    }
};