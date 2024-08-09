// Rotate a Linked List

/*
Given the head of a singly linked list, the task is to rotate the linked list clockwise by k nodes, 
i.e., left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example1:
    Input: 
        linkedlist: 2->4->7->8->9 , k = 3
    Output: 
        8->9->2->4->7
    Explanation:
        Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
        Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
        Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

Example2:
    Input: 
        linkedlist: 1->2->3->4->5->6->7->8 , k = 4
    Output: 
        5->6->7->8->1->2->3->4

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 <= number of nodes <= 10^3
    1 <= node -> data <= 10^4
    1 <= k <= number of nodes 
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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if(head->next == NULL)
            return head;
        Node *temp = head, *temp2 = head;
        while(temp->next) {
            k--;
            if(k == 0) {
                temp2 = temp->next;
                temp->next = NULL;
                temp = temp2;
            }
            else
                temp = temp->next;
        }
        if(temp2 != head)
            temp->next = head;
        return temp2;
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

        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}