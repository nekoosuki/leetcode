#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[0]*a[0]+a[1]*a[1]>b[0]*b[0]+b[1]*b[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,cmp> heap;
        for (auto v:points){
            heap.push(v);
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};