#include <iostream>

using namespace std;

int nthUglyNumber(int n) {
    int dp[n];
    dp[0] = 1;
    int dx2 = 0, dx3 = 0, dx5 = 0;
    for (int i = 1; i < n; i++) {
        int d2 = dp[dx2] * 2, d3 = dp[dx3] * 3, d5 = dp[dx5] * 5;
        int t;
        if (d2 <= d3 && d2 <= d5) {
            t = d2;
            dx2++;
            if (d2 == d3) {
                dx3++;
            }
            if (d2 == d5) {
                dx5++;
            }
        } else if (d3 <= d2 && d3 <= d5) {
            t = d3;
            dx3++;
            if (d2 == d3) {
                dx2++;
            }
            if (d3 == d5) {
                dx5++;
            }
        } else {
            t = d5;
            dx5++;
            if (d2 == d5) {
                dx2++;
            }
            if (d3 == d5) {
                dx3++;
            }
        }
        dp[i] = t;
    }
    return dp[n - 1];
}

int main(int argc, char const *argv[]) {
    cout << nthUglyNumber(2) << endl;
    return 0;
}
