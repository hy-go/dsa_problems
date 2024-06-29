// 29th June 2024
// Identical Linked List

/*
Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false. 

Example1:
  Input:
    LinkedList1: 1->2->3->4->5->6
    LinkedList2: 99->59->42->20
  Output: 
    false

Example2:
  Input: 
    LinkedList1: 1->2->3->4->5
    LinkedList2: 1->2->3->4->5
  Output: 
    true
*/

#include <bits/stdc++.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool areIdentical(struct Node *head1, struct Node *head2);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2, tmp, d1, d2;
        struct Node *head1 = NULL, *tail1 = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n1;
        cin >> d1;
        head1 = new Node(d1);
        tail1 = head1;
        while (n1-- > 1) {
            cin >> tmp;
            tail1->next = new Node(tmp);
            tail1 = tail1->next;
        }
        cin >> n2;
        cin >> d2;
        head2 = new Node(d2);
        tail2 = head2;
        while (n2-- > 1) {
            cin >> tmp;
            tail2->next = new Node(tmp);
            tail2 = tail2->next;
        }

        areIdentical(head1, head2) ? cout << "true" << endl : cout << "false" << endl;
    }
    return 0;
}

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// Function to check whether two linked lists are identical or not.
bool areIdentical(struct Node *head1, struct Node *head2) {
    if(!head1 && !head2)
        return true;
    if(!head1 || !head2 || head1->data != head2->data)
        return false;
    return areIdentical(head1->next, head2->next);
}
