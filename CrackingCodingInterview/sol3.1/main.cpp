#include <iostream>
#include <stack>
#define MAX 100
using namespace std;

class stackk {
   static int arr[MAX][2];
   static int counter;
public:
    int id, top;
    void init_stack (){
    for (int i = 0; i< MAX; i++){
        stackk::arr[i][0] = -1;
        stackk::arr[i][1] = -1;
    }
    }
    void push(int num) {
        arr[counter][0] = num;
        arr[counter][1] = top;
        top = counter;
        while (arr[counter][0] != -1){
            counter++;
            if (counter >= MAX) {
                counter = 0;
            }
            //cout << "\nTop:" << top << "counter:" << counter << "arr:" << arr[counter][0] << endl;
            if (top == counter) {
                cout << "\nArray is full huh!";
                break;
            }
        }
    }
    int pop() {
        if (top == -1)
            return -1;
        int ret = arr[top][0];
        arr[top][0] = -1;
        top = arr[top][1];
        return ret;
    }
};

class stackA : public stackk {
    public:
    stackA() {
        id = 1;
        top = -1;
    }
};
class stackB : public stackk {
    public:
    stackB() {
        id = 2;
        top = -1;
    }
};
class stackC : public stackk {
    public:
    stackC() {
        id = 3;
        top = -1;
    }
};


int stackk::arr[MAX][2] = {{-1}};
int stackk::counter = 0;

int main() {
    stackA stkA;
    stackB stkB;
    stackC stkC;
    stackk().init_stack();
    std::stack<int> teststkA, teststkB, teststkC;
    for (int i = 0; i < MAX; i++) {
        int tok = rand() %100;
        if (tok % 3 == 0) {
            if (tok % 2 == 0) {
                cout << "\nPushing A:" << tok; 
                stkA.push(tok);
                teststkA.push(tok);
            } else {
               if (!teststkA.empty()) {
                   cout << endl << "Poping A:" << ((stkA.pop() == teststkA.top()) ? "True :" : "False :") << teststkA.top();
                   teststkA.pop();
               } else {
                   cout << endl << "Poping A:" << stkA.pop();
               }
            }
        }
        if (tok % 3 == 1) {
            if (tok % 2 == 0) {
                cout << "\nPushing B:" << tok; 
                stkB.push(tok);
                teststkB.push(tok);
            } else {
               if (!teststkB.empty()) {
                   cout << endl << "Poping B:" << ((stkB.pop() == teststkB.top()) ? "True :" : "False :") << teststkB.top();
                   teststkB.pop();
               } else {
                   cout << endl << "Poping B:" << stkB.pop();
               }
            }
        }
        if (tok % 3 == 2) {
            if (tok % 2 == 0) {
                cout << "\nPushing C:" << tok; 
                stkC.push(tok);
                teststkC.push(tok);
            } else {
               if (!teststkC.empty()) {
                   cout << endl << "Poping C:" << ((stkC.pop() == teststkC.top()) ? "True :" : "False :") << teststkC.top();
                   teststkC.pop();
               } else {
                   cout << endl << "Poping C:" << stkC.pop();
               }
            }
        }
    }
}
