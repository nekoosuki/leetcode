#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool start(vector<vector<char>>& board,vector<vector<bool>>& visited, int i, int j, int cur, string word){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()){
            return false;
        }
        if(visited[i][j]){
            return false;
        }
        if(word[cur] != board[i][j]){
            return false;
        }
        if(++cur>=word.length()){
            return true;
        }
        visited[i][j] = true;
        bool found = start(board,visited,i-1,j,cur,word)||start(board,visited,i+1,j,cur,word)||start(board,visited,i,j-1,cur,word)||start(board,visited,i,j+1,cur,word);
        visited[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(start(board,visited,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};