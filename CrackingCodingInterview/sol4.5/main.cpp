#include <iostream>
#include <array>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node (int num) {
        data = num;
        left = NULL;
        right = NULL;
    }
};

node* form_tree(array<int,10> arr, int first, int last) {
    int mid = (first + last) / 2;
    node* head = new node(arr[mid]);
    if (last <= first) {
        if (last == first)
            return new node(arr[first]);
        else
            return NULL;
    } else {
        head -> left = form_tree(arr, first, mid -1);
    }
    if (first >= last) {
        if (first == last)
            return new node(arr[first]);
        else
            return NULL;
    } else {
        head -> right = form_tree(arr, mid + 1, last);
    }
    return head;
}

void print_inorder(node* head, int space) {
    if (head == NULL)
        return;

    space += 5;

    print_inorder(head->right, space);
    cout << endl;
    for (int i = 0; i < space; i++) cout << " ";
    cout << head->data;
    print_inorder(head->left, space);
}


bool checkBst(struct node* root, int min, int max) {
    if (root == NULL)
        return true;
    cout << endl << "Am checking : " << root->data << " with min " << min << " and max "<< max;
    bool check = (checkBst(root->left, min, root->data) & checkBst(root->right, root->data, max));
    if (check == false)
        return false;
    if (root->data > min && root->data <= max)
        return true;
    else
        return false;
}

int main() {
    array<int,10> arr {1,2,3,3,5,6,7,8,9,10};
    node* head = form_tree(arr, 0, 9);
    print_inorder(head, 0);
    bool ret = checkBst(head, -999999, 999999);
    if (ret)
        cout << endl << "Tree is BST";
    else
        cout << endl << "Tree is not a BST";
    return 0;
}

