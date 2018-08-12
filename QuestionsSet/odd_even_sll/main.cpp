/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* tmpHead = head;
        ListNode* oddPtrH = tmpHead;
        ListNode* oddPtr = tmpHead;
        ListNode* evenPtr = tmpHead -> next;
        ListNode* evenPtrH = tmpHead -> next;
        if (tmpHead -> next == NULL)
            return head;
        
        while (oddPtr -> next ->next != NULL && evenPtr -> next -> next != NULL) {
            oddPtr -> next = oddPtr -> next -> next;
            oddPtr = oddPtr -> next;
            evenPtr -> next = evenPtr -> next -> next;
            evenPtr = evenPtr -> next;
        }
        
        if (oddPtr -> next -> next != NULL) {
            oddPtr -> next = oddPtr -> next -> next;
            oddPtr = oddPtr -> next;
        }
        oddPtr -> next = NULL;
        evenPtr -> next = NULL;
        oddPtr -> next = evenPtrH;
        return oddPtrH;
    }
};
