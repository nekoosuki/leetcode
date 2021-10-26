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
    string mul(string str, char c){
        int carry = 0;
        string res;
        for(int i=str.length()-1; i>=0; i--){
            int t = (str[i]-'0')*(c-'0')+carry;
            res = to_string(t%10)+res;
            carry = t/10;
        }
        if(carry!=0) res = to_string(carry)+res;
        return res;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        if(num1=="1") return num2;
        if(num2=="1") return num1;
        
        string res;
        for(int i=num2.size()-1, j=0; i>=0; i--,j++){
            string mulRes = mul(num1, num2[i]);
            for(int k=0; k<j; k++){
                mulRes += "0";
            }
            res = addStrings(res, mulRes);
        }
        return res;
    }
};