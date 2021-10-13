#include <stack>

using namespace std;

class MyQueue {
   private:
    stack<int> in, out;
    void in2out(){
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
   public:
    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if(out.empty()){
            in2out();
        }
        int t = out.top();
        out.pop();
        return t;
    }

    int peek() {
    if(out.empty()){
        in2out();
    }
        return out.top();
    }

    bool empty() {
        return in.empty()&&out.empty();
    }
};