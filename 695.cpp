#include <vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res = max(res, helper(grid,i,j));
            }
        }
        return res;
    }
    int helper(vector<vector<int>>& grid, int i, int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)return 0;
        grid[i][j]=0;
        int count=1;
        count+=helper(grid, i-1,j);
        count+=helper(grid,i+1,j);
        count+=helper(grid,i,j-1);
        count+=helper(grid,i,j+1);
        return count;
    }
};