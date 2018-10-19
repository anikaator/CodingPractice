class Solution {
public:
    int findHeight(TreeNode *root, int& currmax) {
        if(root == NULL)
            return 0;
        int leftht = findHeight(root->left, currmax);
        int rightht = findHeight(root->right, currmax);
        if (currmax < (leftht + rightht))
            currmax = (leftht + rightht);
        return max(leftht, rightht) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int currmax = 0;
        if(root == NULL)
            return 0;
        if (root->right == NULL && root->left == NULL)
            return 0;
        findHeight(root, currmax);
        return currmax;
    }
    

};
