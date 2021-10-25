#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    static vector<string> split(const string &s, const string &seperator) {
        vector<string> result;
        typedef string::size_type string_size;
        string_size i = 0;

        while (i != s.size()) {
            int flag = 0;
            while (i != s.size() && flag == 0) {
                flag = 1;
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[i] == seperator[x]) {
                        ++i;
                        flag = 0;
                        break;
                    }
            }
            flag = 0;
            string_size j = i;
            while (j != s.size() && flag == 0) {
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[j] == seperator[x]) {
                        flag = 1;
                        break;
                    }
                if (flag == 0) ++j;
            }
            if (i != j) {
                result.push_back(s.substr(i, j - i));
                i = j;
            }
        }
        return result;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        vector<string> strings = split(s, " ");
        vector<char> inmapkeys;
        if(strings.size() != pattern.size())return false;
        for(int i=0; i<pattern.size();i++){
            auto it = m.find(pattern[i]);
            if(it == m.end()){
                for(auto it = m.begin();it != m.end();it++){
                    if(it->first != pattern[i] && it->second == strings[i])return false;
                }
                m[pattern[i]] = strings[i];
                inmapkeys.push_back(pattern[i]);
            }else if(it->second != strings[i]){
                return false;
            }
        }
        return true;
    }
};