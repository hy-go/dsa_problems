// Quick Sort on Linked List

/*
You are given a Linked List.
Sort the given Linked List using quicksort. 

Example1:
    Input: Linked list: 1->6->2
    Output: 1->2->6

Example2:
    Input: Linked list: 1->9->3->8
    Output: 1->3->8->9

Constraints:
  1 <= size of linked list <= 10^5

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(1)
*/

#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution {
  public:
    pair<struct Node*, struct Node*> partition(struct Node* head) {
        struct Node *dummyHead1 = new struct Node(-1), *dummyHead2 = new struct Node(-1);
        struct Node *temp1 = dummyHead1, *temp2 = dummyHead2, *temp = head->next;
        head->next = NULL;
        while(temp) {
            if(temp->data < head->data) {
                temp1->next = temp;
                temp1 = temp;
            }
            else {
                temp2->next = temp;
                temp2 = temp;
            }
            temp = temp->next;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        return {dummyHead1->next, dummyHead2->next};
    }
    
    struct Node* quickSort(struct Node* head) {
        if(!head)
            return NULL;
        pair<struct Node*, struct Node*> headPair = partition(head);
        struct Node *head1 = headPair.first, *head2 = headPair.second;
        head1 = quickSort(head1);
        head2 = quickSort(head2);
        Node *temp;
        if(head1) {
            temp = head1;
            while(temp->next)
                temp = temp->next;
            temp->next = head;
        }
        else
            head1 = head;
        temp = head;
        temp->next = head2;
        return head1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
