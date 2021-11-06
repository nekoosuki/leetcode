#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        queue<int> q;
        visited[0]=1;
        q.push(0);
        while (!q.empty()) {
            int key = q.front();
            q.pop();
            for (int k : rooms[key]) {
                if (!visited[k]) {
                    q.push(k);
                    visited[k] = 1;
                }
            }
        }
        for(int v:visited){
            if(!v)return false;
        }
        return true;
    }
};