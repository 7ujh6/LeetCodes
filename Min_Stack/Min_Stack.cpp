#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


cusing namespace std;
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

int main() {

    MinStack* obj = new MinStack();
    obj->push(-2147483648);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    return 0;
}