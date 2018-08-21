#include <iostream>
#include <stack>
#include <assert.h>
#include <queue>

using namespace std;

class Q {
private:
    stack<int> push_stk;
    stack<int> pop_stk;
public:
    int pop();
    void push(int);
    void transfer2other(stack<int> &, stack<int> &);
};

int Q::pop() {
    if (!pop_stk.empty()) {
        int ret = pop_stk.top();
        pop_stk.pop();
        return ret;
    }
    if (push_stk.empty())
        return -1;
    transfer2other(push_stk, pop_stk);
    int ret = pop_stk.top();
    pop_stk.pop();
    return ret;
}

void Q::push(int num) {
    if (!push_stk.empty()) {
        push_stk.push(num);
        return;
    }
    transfer2other(pop_stk, push_stk);
    push_stk.push(num);
}

void Q::transfer2other(stack<int> &src_stk, stack<int> &dest_stk) {
    while(!src_stk.empty()) {
        dest_stk.push(src_stk.top());
        src_stk.pop();
    }
}

int main() {
    Q my_q;
    queue<int> qu;
    for(int i=0; i<100; ++i) {
        int num = rand() % 100;
        if(num%2 == 0) {
            cout << "\nPushing :" << num;
            qu.push(num);
            my_q.push(num);
        } else {
            if(qu.empty()) {
                assert(my_q.pop() == -1);
                continue;
            }
            int no = my_q.pop();
            cout << "\nPoping :" << no;
            assert(qu.front() == no);
            qu.pop();
        }
    }
    return 0;
}
