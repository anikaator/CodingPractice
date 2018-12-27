/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool compare(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        if(s == NULL || t == NULL) {
            return false;
        }
        if(s->val != t->val) {
            return false;        
        }
                
        return compare(s->left, t->left) && compare(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(s == NULL) {
            return false;
        }
        if(s == NULL && t == NULL) {
            return true;
        }
        
        if(s->val == t->val) {
            if (compare(s, t) == true)
                return true;
        }
        
        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};
