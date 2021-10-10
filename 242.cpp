#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s == t;
}
