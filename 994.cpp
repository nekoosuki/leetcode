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