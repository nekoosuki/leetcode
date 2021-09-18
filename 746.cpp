#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int s = cost.size();
    int tmp = -1;
    for (int i = s - 3, tmp = cost[i + 2]; i >= 0; i--) {
        cost[i] += min(cost[i + 1], tmp);
        tmp = cost[i + 1];
    }
    return min(cost[0], cost[1]);
}

int main(int argc, char const* argv[]) {
    vector<int> v = {10, 15, 20};
    cout << minCostClimbingStairs(v) << endl;
    return 0;
}
