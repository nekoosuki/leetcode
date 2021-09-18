#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int h = triangle.size();
    if (h == 1) {
        return triangle[0][0];
    }
    for (int pos = 1; pos < h; pos++) {
        for (int i = 0; i < h - pos; i++) {
            triangle[h - pos - 1][i] +=
                min(triangle[h - pos][i], triangle[h - pos][i + 1]);
        }
    }
    return triangle[0][0];
}

int main(int argc, char const* argv[]) {
    vector<vector<int>> v = {{-10}};
    cout << minimumTotal(v) << endl;
    return 0;
}
