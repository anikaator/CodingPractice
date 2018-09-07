class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int cntLeft = checkHeight(root->left);
        int cntRight = checkHeight(root->right);
        if (cntLeft == -1 || cntRight == -1)
            return false;
        if(abs(cntLeft - cntRight) > 1)
            return false;
        else 
            return true;
    }
    
    int checkHeight(struct TreeNode* node) {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL)
            return 1;
        int cntLeft = checkHeight(node->left);
        int cntRight = checkHeight(node->right);
        if (cntLeft == -1 || cntRight == -1)
            return -1;
        if(abs(cntLeft - cntRight) > 1)
            return -1;
        else 
            return cntLeft > cntRight ? cntLeft+1 : cntRight+1;        
    }
};
