/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string encode(TreeNode* root) {
        if (root == NULL) {
            return " null ";
        }        
        string s = " " + to_string(root->val) + " " + encode(root->left) + " " + encode(root->right) + " ";
        return s;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        s = encode(root);
        return s;
    }

    TreeNode* decode(stringstream& ss) {
        string token;
        TreeNode* root = NULL;
        if (ss >> token) {
            if(token.compare("null") !=0) {
                root = new TreeNode(stoi(token));
                root->left = decode(ss);
                root->right = decode(ss);
            }            
        }        
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        stringstream ss(data);
        return decode(ss);
    }
};
