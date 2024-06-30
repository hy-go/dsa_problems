// 30th June 2024
// Delete node in Doubly Linked List

/*
Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list. 

Example1:
  Input:
      LinkedList = 1 <--> 3 <--> 4, x = 3
  Output: 
      1 3  

Example2:
  Input: 
    LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
  Output: 
    5 2 9
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x == 1) {
            if(head->next)
                head->next->prev = NULL;
                return head->next;
        }
        head->next = deleteNode(head->next, x-1);
        return head;
    }
};

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}
