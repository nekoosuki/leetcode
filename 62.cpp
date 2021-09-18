#include <iostream>

using namespace std;

int uniquePaths(int m, int n) {
    int s = max(m, n);
    unsigned int count[s + 1][s + 1];
    for (int i = 0; i <= s; i++) {
        count[i][0] = 0;
    }
    for (int i = 0; i <= s; i++) {
        count[0][i] = 0;
    }
    count[1][1] = 1;
    for (int i = 1; i <= s; i++) {
        for (int j = i; j <= s; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            count[i][j] = count[i - 1][j] + count[j - 1][i];
            count[j][i] = count[i][j];
        }
    }
    return count[m][n];
}

int main(int argc, char const *argv[]) {
    cout << uniquePaths(23, 12) << endl;
    return 0;
}
