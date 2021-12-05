#include <vector>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowm(grid.size()), colm(grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                rowm[i] = max(rowm[i],grid[i][j]);
                colm[j] = max(colm[j],grid[i][j]);
            }
        }
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res += min(rowm[i],colm[j])-grid[i][j];
            }
        }
        return res;
    }
};