#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> spath(n);
        vector<int> res(n,0);
        //按序排列路径
        //2,0;2,1;3,1;3,2
        for(vector<int>path : paths){
            if(path[0]>path[1]){
                spath[path[0]-1].push_back(path[1]-1);
            }else{
                spath[path[1]-1].push_back(path[0]-1);
            }
        }
        for(int i=0;i<n;i++){
            auto ipath = spath[i];
            unordered_set<int> usedc;
            for(int conn:ipath){
                usedc.emplace(res[conn]);
            }
            for(int cor=1;cor<=4;cor++){
                if(usedc.find(cor)==usedc.end()){
                    res[i]=cor;
                    break;
                }
            }
        }
        return res;
    }
};