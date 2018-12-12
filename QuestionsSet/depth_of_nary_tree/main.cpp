/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        if(root->children.size() == 0) {
            return 1;
        }
        int max_depth = -1;
        for (auto c : root->children) {
            max_depth = max(max_depth, maxDepth(c) + 1);
        }
        return max_depth;        
    }
};
