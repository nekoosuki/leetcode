#include <vector>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> res;
    unordered_map<char, int> map;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        map[s[i]] = i;
    }
    for (int i = 0; i < s.size(); i++) {
        end = max(end, map[s[i]]);
        if (i == end) {
            res.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return res;
}