#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 27/48
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     unordered_map<int, vector<pair<int,int>>> fmap;
    //     for(auto flight:flights){
    //         fmap[flight[0]].push_back(make_pair(flight[1],flight[2]));
    //     }
    //     vector<int> distance(n,INT16_MAX);
    //     queue<int> wait;
    //     wait.push(src);
    //     distance[src] = 0;
    //     int ck = 0;
    //     while(!wait.empty()){
    //         vector<int> tmp(distance);
    //         int nodes = wait.size();
    //         int visited = 0;
    //         while(visited < nodes){
    //             int node = wait.front();
    //             wait.pop();
    //             auto fs = fmap[node];
    //             for(auto f:fs){
    //                 tmp[f.first] = min(tmp[f.first],distance[node]+f.second);
    //                 wait.push(f.first);
    //             }
    //             visited++;
    //         }
    //         distance=tmp;
    //         if(ck++>=k) {
    //             break;
    //         }
    //     }
    //     return distance[dst]==INT16_MAX?-1:distance[dst];
    // }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //官方题解
        vector<vector<int>> f(k + 2, vector<int>(n, INT16_MAX));
        f[0][src] = 0;
        for (int t = 1; t <= k + 1; ++t) {
            for (auto&& flight: flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                f[t][i] = min(f[t][i], f[t - 1][j] + cost);
            }
        }
        int ans = INT16_MAX;
        for (int t = 1; t <= k + 1; ++t) {
            ans = min(ans, f[t][dst]);
        }
        return (ans == INT16_MAX ? -1 : ans);
    }
};