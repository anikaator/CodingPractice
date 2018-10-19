class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        traverse(root, "" ,result);
        return result;
    }
    
    void traverse(TreeNode* root, string append, vector<string> & result) {
        if (root == NULL) {
            return;
        }
        string tmp;
        if(append.length() == 0) {
            tmp = to_string(root->val);
        } else {
            tmp = append + "->" + to_string(root->val);    
        }                        

        if(root->right == NULL && root->left == NULL) {
            result.emplace_back(tmp);
        } else {    
            traverse(root->left, tmp, result);
            traverse(root->right, tmp, result);
        }        
    }
    
};
