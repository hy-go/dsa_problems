Sort a k sorted doubly linked list

/*
Given a doubly linked list, each node is at most k-indices away from its target position. 
The problem is to sort the given doubly linked list. 
The distance can be assumed in either of the directions (left and right).

Example1:
    Input: Doubly Linked List : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
    Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

Example2:
    Input: Doubly Linked List : 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
    Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7

Expected Time Complexity: O(n*logk)
Expected Auxiliary Space: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLLNodeCompare {
    public:
        bool operator()(DLLNode *a, DLLNode *b){
           return a->data > b->data;
        }
};

class Solution {
  public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        DLLNode *dummyHead = new DLLNode(-1), *temp = dummyHead;
        priority_queue<DLLNode*, vector<DLLNode*>, DLLNodeCompare> pq;
        for(int i = 0; i < k; ++i) {
            pq.push(head);
            head = head->next;
        }
        while(head) {
            pq.push(head);
            temp->next = pq.top();
            temp->next->prev = temp;
            pq.pop();
            head = head->next;
            temp = temp->next;
        }   
        while(!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        dummyHead->next->prev = NULL;
        return dummyHead->next;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}
