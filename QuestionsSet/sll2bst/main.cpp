class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if ( head == NULL )
            return NULL;
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }
        ListNode* fast = head -> next;
        TreeNode* lastRoot = new TreeNode(head->val);
        while (fast != NULL) {
            TreeNode* root = new TreeNode(fast->val);
            root->left = lastRoot;
            if(fast -> next != NULL) {
                root->right = new TreeNode(fast->next->val);
            }
            lastRoot = root;
            if (fast->next != NULL) {
                if (fast->next->next != NULL) {
                    fast = fast->next->next;
                } else {
                    break;
                }                    
            } else {
                break;
            }            
        }
        return lastRoot;
        
        
    }
};
