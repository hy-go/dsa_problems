// Multiply two Linked Lists
/*
Given elements as nodes of the two singly linked lists. 
The task is to multiply these two linked lists, say L1 and L2.
Note: The output could be large take modulo 10^9+7.

Example1:
    Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
    Output: 64
    Explanation: Multiplication of 32 and 2 gives 64.

Example2:
    Input: LinkedList L1: 12->0->0 , LinkedList L2 : 1->0
    Output: 12000
    Explanation: Multiplication of 1200 and 10 gives 1000.

Expected Time Complexity: O(max(n,m)) where n is the size of L1 and m is the size of L2
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

struct Node *newNode(int data) {
    struct Node *new_Node = new Node(data);

    return new_Node;
}

Node *reverse(Node **r) {
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

void push(struct Node **head_ref, int new_data) {
    /* allocate Node */
    struct Node *new_Node = newNode(new_data);

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node) {
    struct Node *temp;
    while (Node != NULL) {

        temp = Node;
        Node = Node->next;
        free(temp);
    }
}

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long f = 0, s = 0;
        int mod = 1e9 + 7;
        while(first) {
            f = (f * 10 + first->data) % mod;
            first = first->next;
        }
        while(second) {
            s = (s * 10 + second->data) % mod;
            second = second->next;
        }
        return (f * s) % mod;
    }
};

void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

int main(void) {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        struct Node *first = NULL;
        struct Node *second = NULL;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }
        for (int i = 0; i < arr.size(); i++) {
            push(&first, arr[i]);
        }
        vector<int> brr;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number1;
        while (ss2 >> number1) {
            brr.push_back(number1);
        }
        for (int i = 0; i < brr.size(); i++) {
            push(&second, brr[i]);
        }
        reverse(&first);
        reverse(&second);
        solution ob;
        long long res = ob.multiplyTwoLists(first, second);
        cout << res << endl;
        freeList(first);
        freeList(second);
    }
    return 0;
}
