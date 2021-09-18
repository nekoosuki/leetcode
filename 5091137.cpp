#include <iostream>

using namespace std;

int fib(int n) {
    if (n < 2) {
        return n;
    }
    if (n == 2) {
        return 1;
    }
    int p = 0, q = 1, r = 1, s = 0;
    for (int i = 3; i <= n; i++) {
        s = p + q + r;
        p = q;
        q = r;
        r = s;
    }
    return s;
}

int main(int argc, char const *argv[]) {
    cout << fib(25) << endl;
    return 0;
}
