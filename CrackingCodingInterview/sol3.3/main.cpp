#include <iostream>
#include <stack>
#include <vector>
#include <assert.h>
#define MAX 10
using namespace std;

class SetofStack {
private:
    vector <stack<int>*> multiStk;
    int curr = 0;
public:
    int pop();
    void push(int);
    int getcurr() {
        return curr;
    }
    SetofStack() {
        stack<int> *tmpStk = new stack<int>;
        multiStk.push_back(tmpStk);
    }
};

int SetofStack::pop() {
    while((multiStk[curr]->empty()) && curr != 0) {
        multiStk.erase(multiStk.begin() + curr );
        curr --;
    }
    if (multiStk[curr]->empty()) {
        return -1;
    }
    int ret = multiStk[curr]->top();
    multiStk[curr]->pop();
    return ret;
}

void SetofStack::push(int num) {
    if (multiStk[curr]->size() >= MAX) {
        curr++;
    }
    if (multiStk[curr] == NULL) {
        stack<int> *tmpStk = new stack<int>;
        multiStk.push_back(tmpStk);
    }
    multiStk[curr]->push(num);
}

int main() {
    SetofStack stk;
    stack<int> teststk;
    for (int i = 0; i < 1000; i++) {
        int num = rand() % 100;
        if (num % 3 != 0) {
            cout << "\nPushing element :" << num << ": curr " << stk.getcurr();
            stk.push(num);
            teststk.push(num);
        } else {
            if (teststk.size() == 0) {
                cout << "\nPoping empty";
                assert(stk.pop() == -1);
                continue;
            }
            cout << "\nPoping element :" << teststk.top() << ": curr " << stk.getcurr();
            assert(stk.pop() == teststk.top());
            teststk.pop();
        }
    }
    return 0;
}

