#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int trap(vector<int>& height) {
    int sum = 0;
    int s = height.size();
    if(s == 0){
        return 0;
    }
    int hei[s][2];
    hei[0][0] = height[0];
    hei[s - 1][1] = height[s - 1];
    for (int i = 1; i < s; i++) {
        hei[i][0] = max(hei[i - 1][0], height[i]);
    }
    for (int i = s - 2; i >= 0; i--) {
        hei[i][1] = max(hei[i + 1][1], height[i]);
    }
    for (int i = 0; i < s; i++) {
        sum += min(hei[i][0], hei[i][1]) - height[i];
    }
    return sum;
}

int main(int argc, char const* argv[]) {
    vector<int> v = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2,
                     7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
    cout << trap(v) << endl;
    return 0;
}
