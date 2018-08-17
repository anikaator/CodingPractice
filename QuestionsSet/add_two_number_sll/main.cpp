class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* node = NULL;
        int carry = 0;
        int sum = 0;
        while (l1 != NULL && l2 != NULL) {
            if (head == NULL) {
                sum = l1->val + l2->val + carry;            
                carry = sum / 10;                
                sum = sum % 10;
                head = new ListNode(sum);
                node = head;                    
                l1 = l1 -> next;
                l2 = l2 -> next;
                continue;
            }
            sum = l1->val + l2->val + carry;            
            carry = sum / 10;                
            sum = sum % 10;
            node->next = new ListNode(sum);
            node = node -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while (l1 != NULL) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;                
            node->next = new ListNode(sum);
            node = node ->next;
            l1 = l1 -> next;        
        }
        while (l2 != NULL) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;                
            node->next = new ListNode(sum);
            node = node ->next;
            l2 = l2 -> next;        
        }
        if (carry > 0) {
            node->next = new ListNode(carry);
        }
        
        return head;
    }
};
