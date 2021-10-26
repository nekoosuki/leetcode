#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for(string str:strs){
            string key = str;
            sort(key.begin(),key.end());
            m[key].push_back(str);
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};