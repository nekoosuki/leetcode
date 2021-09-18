#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int p = 1, q = 2, r = 0;
    for (int i = 3; i <= n; i++) {
        r = p + q;
        p = q;
        q = r;
    }
    return r;
}

int main(int argc, char const *argv[])
{
    cout << climbStairs(3) <<endl;
    return 0;
}
