#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int path(vector<vector<int>>& matrix, vector<vector<int>>& visited,int i, int j,int k){
        int m = matrix.size(), n = matrix[0].size();
        if(i<0||i>=m||j<0||j>=n){
            return 0;
        }
        int num = matrix[i][j];
        if(num <= k){
            return 0;
        }
        if(visited[i][j]>0)return visited[i][j];
        visited[i][j] = max(max(max(path(matrix,visited,i-1,j,num),path(matrix,visited,i+1,j,num)),path(matrix,visited,i,j-1,num)),path(matrix,visited,i,j+1,num))+1;
        return visited[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res = max(res,path(matrix,visited,i,j,INT32_MIN));
            }
        }
        return res;
    }
};