#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> pre = {1};
    for (int i = 1; i <= rowIndex + 1; i++) {
        vector<int> tmp;
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1) {
                tmp.push_back(1);
            } else {
                tmp.push_back(pre[j - 1] + pre[j]);
            }
        }
        pre.assign(tmp.begin(), tmp.end());
    }
    return pre;
}

int main(int argc, char const *argv[]) {
    vector<int> v = getRow(0);
    for (int e : v) {
        cout << e << ',';
    }
    return 0;
}
