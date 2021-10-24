#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1,add=0;
        string res;
        while(i>=0||j>=0||add!=0){
            int a=i>=0?num1[i]-'0':0;
            int b=j>=0?num2[j]-'0':0;
            res.push_back('0'+(a+b+add)%10);
            add = (a+b+add)/10;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};