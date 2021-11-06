#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1&&trust.empty())return 1;
        unordered_map<int,int>in, out;
        for(auto e:trust){
            out[e[0]]++;
            in[e[1]]++;
        }
        for(auto it=in.begin(); it!=in.end();it++){
            if(it->second==n-1){
                if(out[it->first]==0)return it->first;
            }
        }
        return -1;
    }
};