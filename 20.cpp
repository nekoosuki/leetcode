#include <stack>
#include <iostream>

using namespace std;

bool isValid(string s) {
    stack<char> v;
    for(char c : s){
        if(c=='('||c=='{'||c=='['){
            v.push(c);
        }else{
            if(v.empty()){
                return false;
            }
            const char a = v.top();
            v.pop();
            if(!(c==')'&&a=='('||c=='}'&&a=='{'||c==']'&&a=='[')){
                return false;
            }
        }
    }
    if(v.empty()){
        return true;
    }
    return false;
}
