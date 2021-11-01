#include <stack>
#include <iostream>
#include <limits>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> mins;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(mins.empty()||val <= mins.top()){
            mins.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(s.top()==mins.top()){
            mins.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
