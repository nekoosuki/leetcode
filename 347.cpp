#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num:nums)m[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto p:m){
            if(heap.size()==k){
                if(heap.top().first < p.first){
                    heap.pop();
                    heap.push(make_pair(p.second,p.first));
                }
            }else{
                heap.push(make_pair(p.second,p.first));
            }
        }
        vector<int> res;
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
