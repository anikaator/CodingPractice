#include <list>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *master = NULL;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tempPtr = head;
        ListNode *secPtr;
        bool started = false;
        if (tempPtr -> next == NULL && n == 1)
            return NULL;
        while(tempPtr->next != NULL) {
            if (n == 1) {
                secPtr = head;
                started = true;
                n = 0;
                tempPtr =  tempPtr -> next;
                continue;
            }
            if (started == true) {
                secPtr = secPtr -> next;
            } else {
                n--;
            }
            tempPtr =  tempPtr -> next;
        }

        if (n >= 1)
            return head ->next;
        if (secPtr -> next  != NULL) {
            secPtr -> next  = secPtr -> next -> next;
        }
        return head;
    }

    void createList() {
        ListNode *tempPtr=master;
        for (int n=0; n < 10; n++) {
            if (tempPtr == NULL) {
                master = new ListNode(rand()%100);
                tempPtr=master;
                continue;
            }
            tempPtr -> next =  new ListNode(rand()%100);
            tempPtr = tempPtr -> next;
        }
    }
    void printList() {
        ListNode *tempPtr=master;
        cout << endl;
        while (tempPtr != NULL ){
            cout << "->" << tempPtr->val;
            tempPtr = tempPtr -> next;
        }
    }
};


int main() {
        Solution().createList();
        Solution().printList();
        cout << "\nRemove 3rd element from end.";
        master = Solution().removeNthFromEnd(master, 3);
        Solution().printList();
        return 0;
}
