// Deletion and Reverse in Circular Linked List

/*
Given a Circular Linked List. 
The task is to delete the given node, key in the circular linked list, and reverse the circular linked list.
Note: You don't have to print anything, just return head of the modified list in each function.

Example1:
    Input: Linked List: 2->5->7->8->10, key = 8
    Output: 10->7->5->2 
    Explanation:
        After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. 
        Now, reversing this list will result in 10, 7, 5, 2.

Example2:
    Input: Linked List: 1->7->8->10, key = 8
    Output: 10->7->1
    Explanation: 
        After deleting 8 from the given circular linked list, it has elements as 1, 7,10. 
        Now, reversing this list will result in 10, 7, 1.

Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
    2 <= number of nodes, key  <= 10^5
    1 <= node -> data <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}

class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node *prev = head, *curr = head, *next;
        while(prev->next != head)
            prev = prev->next;
        while(next != head) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node *prev = head, *curr = head->next;
        if(head->data == key) {
            while(prev->next != head)
                prev = prev->next;
            prev->next = head->next;
            free(head);
            return prev->next;
        }
        while(curr != head) {
            if(curr->data == key) {
                prev->next = curr->next;
                free(curr);
                return head;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}
