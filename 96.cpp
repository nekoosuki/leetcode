#include <iostream>

using namespace std;

int numTrees(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            //把第j个节点作为根节点
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[]) {
    cout << numTrees(3) << endl;
    return 0;
}
