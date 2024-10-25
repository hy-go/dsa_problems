// Occurrence of an integer in a Linked List

/*
Given a singly linked list and a key, 
count the number of occurrences of the given key in the linked list.

Example1:
    Input: Linked List: 1->2->1->2->1->3->1, key = 1
    Output: 4

Example2:
    Input: Linked List: 1->2->1->2->1, key = 3
    Output: 0

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 ≤ number of nodes, key ≤ 10^5
    1 ≤ data of node ≤ 10^5
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
    int count(struct Node* head, int key) {
        int c = 0;
        while(head) {
            if(head->data == key)
                c++;
            head = head->next;
        }
        return c;
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
        int key;
        cin >> key;
        cin.ignore();
        Solution ob;
        cout << ob.count(head, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
