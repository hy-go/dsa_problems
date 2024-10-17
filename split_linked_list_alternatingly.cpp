// Split Linked List Alternatingly

/*
Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. 
The sublists should be made from alternating elements from the original list.

Note: 
    The sublist should be in the order with respect to the original list.
    Your have to return an array containing the both sub-linked lists.

Example1:
    Input: LinkedList = 0->1->0->1->0->1
    Output: 0->0->0 , 1->1->1

Example2:
    Input: LinkedList = 2->5->8->9->6
    Output: 2->8->6 , 5->9

Example3:
    Input: LinkedList: 7 
    Output: 7 , <empty linked list>

Constraints:
    1 <= number of nodes <= 100
    1 <= node -> data <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        if(!head->next)
            return {head, NULL};
        Node *head1 = head, *head2 = head->next, *temp1 = head1, *temp2 = head2;
        head = head2->next;
        while(head) {
            temp1->next = head;
            temp2->next = head->next;
            head = head->next ? head->next->next : NULL;
            temp1 = temp1->next;
            if(temp2->next) temp2 = temp2->next;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        return {head1, head2};
    }
};

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}
