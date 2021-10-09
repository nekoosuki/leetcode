#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> row(9, vector<bool>(9));
    vector<vector<bool>> col(9, vector<bool>(9));
    vector<vector<bool>> block(9, vector<bool>(9));

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] != '.'){
                int num = board[i][j] - '1';
                if(row[i][num] || col[j][num] || block[i/3*3+j/3][num]){
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                block[i/3*3+j/3][num] = true;
            }
        }
    }
    return true;
}