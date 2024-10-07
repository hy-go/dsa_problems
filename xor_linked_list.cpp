// XOR Linked List - A Memory Efficient Linked List

/*
An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. 
A memory-efficient version of the Doubly Linked List can be created using only one space for the address field with every node. 
This memory-efficient Doubly Linked List is called XOR Linked List or Memory Efficient 
as the list uses bit-wise XOR operation to save space for one address.
Given a stream of data of size N for the linked list, your task is to complete the function insert() and getList(). 
The insert() function pushes (or inserts at the beginning) the given data in the linked list and 
the getList() function returns the linked list as a list.

Note:
    A utility function XOR() takes two Node pointers to get the bit-wise XOR of the two Node pointers. 
    Use this function to get the XOR of the two pointers.
    The driver code prints the returned list twice, once forward and once backwards.

Example1:
    Input:
        LinkedList: 9<->5<->4<->7<->3<->10
    Output:
        10 3 7 4 5 9
        9 5 4 7 3 10

Example2:
    Input:
        LinkedList: 58<->96<->31
    Output:
        31 96 58
        58 96 31

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 <= number of nodes, data of nodes <= 10^5
*/

#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    struct Node *nn = new struct Node(data);
    // No need for the edge case due to the constraint
    // in the description, but used for generalization
    if(head) {
        nn->npx = XOR(NULL, head);
        head->npx = XOR(nn, XOR(NULL, head->npx));
    }
    return nn;
}

vector<int> getList(struct Node *head) {
    vector<int> list;
    Node *prev = NULL, *curr = head, *next;
    while(curr) {
        next = XOR(curr->npx, prev);
        list.push_back(curr->data);
        prev = curr;
        curr = next;
    }
    return list;
}
