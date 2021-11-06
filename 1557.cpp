#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,bool>m;
        vector<int> res;
        for(int i=0;i<n;i++)m[i]=true;
        for(auto e:edges){
            m[e[1]]=false;
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second)res.push_back(it->first);
        }
        if(res.empty())return {0};
        return res; 
    }
};