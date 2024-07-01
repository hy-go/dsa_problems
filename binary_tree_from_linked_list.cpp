// 1st July 2024
// Make Binary Tree from Linked List 

/*
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree and print the level order traversal of the Binary tree. 
Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. 
      H is the height of the tree and this space is used implicitly for the recursion stack.

Example1:
    Input: 
        n = 5, k = 10->7->4->3->2
    Output: 
        The tree would look like
              10
            /   \
           7     4
         /  \
        3    2
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        Node *prevhead = head;
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) {
            cout << "-1\n";
        } else if (root == NULL && prevhead != NULL) {
            cout << "-1\n";
        } else {
            lvl(root);
            cout << endl;
        }
        // inorder(root);
        getchar();
    }
    return 0;
}

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    head = head->next;
    q.push(root);
    TreeNode *r;
    while(head) {
        r = q.front();
        r->left = new TreeNode(head->data);
        q.push(r->left);
        head = head->next;
        if(head) {
            r->right = new TreeNode(head->data);
            q.push(r->right);
            head = head->next;
        }
        q.pop();
    }
}
