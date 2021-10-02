#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins) {
    if (amount == 0) {
        return 1;
    }
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = 1; i <= amount; i++) {
            if (i - coin >= 0) dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}
int main(int argc, char const* argv[]) {
    vector<int> v = {1, 2,5};
    cout << change(5, v);
    return 0;
}