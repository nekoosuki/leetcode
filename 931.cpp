#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    for(int i=matrix.size()-2;i>=0;i--){
        for(int j=0;j<matrix[0].size();j++){
            if(j == 0){
                matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j+1]);
            }else if(j>0 && j<matrix[0].size()-1){
                matrix[i][j] += min(min(matrix[i+1][j-1],matrix[i+1][j]),matrix[i+1][j+1]);
            }else{
                matrix[i][j] += min(matrix[i+1][j-1],matrix[i+1][j]);
            }
        }
    }
    return *min_element(matrix[0].begin(),matrix[0].end());
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {{2,1,3},{6,5,4},{7,8,9}};
    cout << minFallingPathSum(v) << endl;
    return 0;
}
