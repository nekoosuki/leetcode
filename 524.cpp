#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    static bool cmp(string& a, string& b) {
        if (a.length() > b.length()) {
            return true;
        } else if (a.length() < b.length()) {
            return false;
        } else {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] > b[i]) {
                    return false;
                } else if (a[i] < b[i]) {
                    return true;
                }
            }
            return true;
        }
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);
        for(string word:dictionary){
            int i=0,j=0;
            while(i<s.length()){
                if(s[i]==word[j]){
                    j++;
                }
                i++;
                if(j==word.length())return word;
            }
        }
        return "";
    }
};