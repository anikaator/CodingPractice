#include <stack>
#include <iostream>

class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> minStk;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
       if (minStk.empty() || minStk.top() >= x )
            minStk.push(x);        
    }
    
    void pop() {        
        if(minStk.top() == stk.top())
            minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

int main() {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    std::cout << std::endl << obj.getMin();
    obj.pop();
    std::cout << std::endl << obj.top();
    std::cout << std::endl << obj.getMin();
}
