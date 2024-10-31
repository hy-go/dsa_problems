// Insert in Sorted way in a Sorted DLL

/*
Given a sorted doubly linked list and an element x, 
you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

Note: The DLL is sorted in ascending order

Example1:
    Input: LinkedList: 3->5->8->10->12 , x = 9
    Output: 3->5->8->9->10->12

Example2:
    Input: LinkedList: 1->4->10->11 , x = 15
    Output: 1->4->10->11->15

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= number of nodes <= 103
1 <= node -> data , x <= 104
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node* nn = getNode(x);
        if(head->data >= x) {
            nn->next = head;
            
            head->prev = nn;
            return nn;
        }
        Node *temp = head;
        while(temp->next && temp->next->data < x) {
            temp = temp->next;
        }
        nn->next = temp->next;
        nn->prev = temp;
        if(nn->next)
            nn->next->prev = nn;
        temp->next = nn;
        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}
