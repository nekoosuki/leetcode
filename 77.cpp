#include <iostream>
#include <vector>
using namespace std;
class Solution {
   private:
    vector<vector<int>> res;
    vector<int> path;
    void traceback(int n, int k, int cur) {
        if (path.size() + (n - cur + 1) < k) {
            return;
        }
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        path.push_back(cur);
        traceback(n, k, cur + 1);
        path.pop_back();
        traceback(n, k, cur + 1);
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        traceback(n, k, 1);
        return res;
    }
};