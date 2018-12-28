#include <iostream>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// fill in the definitions for push(), pop(), and getMax()

struct mystk {
    int data;
    int max;
    mystk(int data, int max):data(data), max(max){}
};

class MaxStack
{
    std::stack<mystk> stk;
public:
    
    void push(int item)
    {
        if(stk.empty()) {
            stk.push(mystk(item, item));
            return;
        }
        int currmax = stk.top().max;
        if(currmax > item) {
            stk.push(mystk(item, currmax));
        } else {
            stk.push(mystk(item, item));
        }
    }

    int pop()
    {
        if(stk.empty()) {
            return 0;
        }
        mystk tmp = stk.top();
        stk.pop();
        return tmp.data;
    }

    int getMax() const
    {
        if (!stk.empty())
            return stk.top().max;
        return -1;    
    }
};


// tests

const lest::test tests[] = {
    CASE("MaxStack test") {
        MaxStack s;
        s.push(5);
        EXPECT(s.getMax() == 5);
        s.push(4);
        s.push(7);
        s.push(7);
        s.push(8);
        EXPECT(s.getMax() == 8);
        EXPECT(s.pop() == 8);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 5);
        EXPECT(s.pop() == 4);
        EXPECT(s.getMax() == 5);
    }
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
