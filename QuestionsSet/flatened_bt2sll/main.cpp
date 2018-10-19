class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* head = root;        
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right != NULL)
            root = root->right;
        root->right = tmp;
        flatten(head->right);        
    }
};
