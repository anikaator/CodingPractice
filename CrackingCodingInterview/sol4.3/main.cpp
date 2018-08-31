#include <iostream>
#include <vector>
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

struct sll {
    int data;
    struct sll *next;
    sll(int num) {
        data = num;
        next = NULL;
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

void list_depth(node* head, vector<sll*>& vec, int curr) {
    if (vec[curr] == NULL) {
        vec[curr] = new sll(head->data);
    } else {
        struct sll* tmp = new sll(head->data);
        tmp->next = vec[curr];
        vec[curr] = tmp;
    }
   if( head->right != NULL)
        list_depth(head->right, vec, curr+1); 
   if( head->left != NULL)
        list_depth(head->left, vec, curr+1); 

}

int main() {
    array<int,10> arr {1,2,3,4,5,6,7,8,9,10};
    vector<sll*> vec(10);
    node* head = form_tree(arr, 0, 9);
    //print_inorder(head, 0);
    list_depth(head, vec, 0);
    int ptr = 0;
    while(vec[ptr] != NULL) {
        struct sll* tmp = vec[ptr];
        while (tmp != NULL) {
            cout << tmp -> data << " ";
            tmp = tmp->next;
        }
        ptr++;
        cout << endl;
    }
            
    return 0;
}

