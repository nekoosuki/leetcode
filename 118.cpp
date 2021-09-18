#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<int> pre = {1};
    vector<vector<int>> res = {{1}};
    for (int i = 2; i <= numRows; i++) {
        vector<int> tmp;
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1) {
                tmp.push_back(1);
            } else {
                tmp.push_back(pre[j - 1] + pre[j]);
            }
        }
        res.push_back(tmp);
        pre.assign(tmp.begin(), tmp.end());
    }
    return res;
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> v = generate(1);
    for (auto v1 : v) {
        for (auto v2 : v1) {
            cout << v2 << ',';
        }
    }
    return 0;
}
