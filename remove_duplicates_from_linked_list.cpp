// 3rd July 2024
// Remove all occurences of duplicates in a linked list

/*
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Example1:
    Input: 
        Linked List = 23->28->28->35->49->49->53->53
    Output: 
        23 35

Example2:
    Input: 
        Linked List = 11->11->11->11->75->75
    Output: 
        Empty list
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

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if(!head) return head;
        if(!head->next || head->next->data != head->data) {
            head->next = removeAllDuplicates(head->next);
            return head;
        }
        int x = head->data;
        while(head && head->data == x)
            head = head->next;
        return removeAllDuplicates(head);
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}
