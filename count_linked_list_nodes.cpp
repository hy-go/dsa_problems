// Count Linked List Nodes

/*
Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

Example1:
    Input: LinkedList : 1->2->3->4->5
    Output: 5

Example2:
    Input: LinkedList : 2->4->6->7->5->1->0
    Output: 7

Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

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
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        if(!head) return 0;
        return 1 + getCount(head->next);
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
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.getCount(head) << endl;
    }
    return 0;
}
