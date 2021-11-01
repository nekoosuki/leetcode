#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> index;
        
        for(int i=0;i<s.size();i++){
            if((s[i]) == '('){
                index.push(i);
            }else if(s[i] == ')'){
                if(index.empty()){
                    s.replace(i--,1,"");
                }else{
                    index.pop();
                }
            }
        }

        while(!index.empty()){
            s.replace(index.top(),1,"");
            index.pop();
        }
        return s;
    }
};