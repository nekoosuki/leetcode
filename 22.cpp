#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<string> func(int i, int j, int n, vector<string> &vs);
vector<string> generateParenthesis(int n) {
    vector<string> t;
    vector<string> v(func(0,0,n,t));
    return v;
}

vector<string> func(int i, int j, int n, vector<string> &vs) {
    if (i == 0) {
        vector<string> v = {"("};
        return func(1, 0, n, v);
    }
    if (i < n && j < i) {
        vector<string> vs1(vs);
        vector<string> vs2(vs);
        for (int k = 0; k < vs1.size(); k++) {
            vs1[k] = vs1[k] + "(";
        }
        for (int k = 0; k < vs2.size(); k++) {
            vs2[k] = vs2[k] + ")";
        }
        vector<string> v1(func(i + 1, j, n, vs1));
        vector<string> v2(func(i, j + 1, n, vs2));
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
    if (i < n && j == i) {
        vector<string> vs1(vs);
        for (int k = 0; k < vs1.size(); k++) {
            vs1[k] = vs1[k] + "(";
        }
        vector<string> v(func(i + 1, j, n, vs1));
        return v;
    }
    if (i == n && j < i) {
        vector<string> vs2(vs);
        for (int k = 0; k < vs2.size(); k++) {
            vs2[k] = vs2[k] + ")";
        }
        vector<string> v2(func(i, j + 1, n, vs2));
        return v2;
    }
    return vs;
}

int main(int argc, char const *argv[]) {
    vector<string> s = generateParenthesis(4);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
    return 0;
}
