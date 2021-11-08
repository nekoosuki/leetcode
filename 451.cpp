#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(pair<char,int>a, pair<char,int>b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int>m;
        for(char c:s)m[c]++;
        vector<pair<char, int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
        string res;
        for(auto it=v.begin();it!=v.end();it++){
            char c=it->first;
            for(int i=0;i<it->second;i++){
                res.push_back(c);
            }
        }
        return res;
    }
};