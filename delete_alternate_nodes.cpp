// Delete Alternate Nodes

/*
Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

Example1:
    Input: LinkedList: 1->2->3->4->5->6
    Output: 1->3->5

Example2:
    Input: LinkedList: 99->59->42->20 
    Output: 99->42

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 <= number of nodes <= 10^5
    1 <= node->data <= 10^3
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
    void deleteAlt(struct Node *head) {
        while(head) {
            if(head->next) {
                Node *temp = head->next;
                head->next = head->next->next;
                free(temp);
            }
            head = head->next;
        }
    }
};

void append(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *head_ref; /* used in step 5*/
    new_node->data = new_data;
          of it as NULL*/
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
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
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        ob.deleteAlt(head);
        printList(head);
    }
    return 0;
}
