#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> m;
    for(char c:magazine){
        m[c]++;
    }
    for(char c:ransomNote){
        m[c]--;
        if(m[c]<0){
            return false;
        }
    }
    return true;
}