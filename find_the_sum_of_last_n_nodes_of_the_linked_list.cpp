// Find the Sum of Last N nodes of the Linked List

/*
Given a single linked list, calculate the sum of the last n nodes.
Note: It is guaranteed that n <= number of nodes.

Example1:
    Input: Linked List: 5->9->6->3->4->10, n = 3
    Output: 17
    Explanation: The sum of the last three nodes in the linked list is 3 + 4 + 10 = 17.

Example2:
    Input: Linked List: 1->2, n = 2
    Output: 3
    Explanation: The sum of the last two nodes in the linked list is 2 + 1 = 3.

Constraints:
    1 <= number of nodes, n <= 10^5
    1 <= node->data <= 10^3

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
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
    int sumOfLastN_Nodes(struct Node* head, int n) {
        struct Node* end = head;
        for(int i = 0; i < n; ++i)
            end = end->next;
        while(end) {
            head = head->next;
            end = end->next;
        }
        int sum = 0;
        while(head) {
            sum += head->data;
            head = head->next;
        }
        return sum;
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
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
