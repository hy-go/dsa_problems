// Palindrome Linked List

/*
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

Example1:
    Input: LinkedList: 1->2->1->1->2->1
    Output: true
    Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

Example2:
    Input: LinkedList: 1->2->3->4
    Output: false
    Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) 
Note: You should not use the recursive stack space as well

Constraints:
    1 <= number of nodes <= 10^5
    1 ≤ node->data ≤ 10^3
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

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
    Node *reverse(Node *head) {
        Node *prev = NULL, *curr = head, *next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        if(!head || !head->next)
            return true;
        Node *slow = head, *fast = head->next->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node *secondHead = slow->next;
        slow->next = NULL;
        bool lenOdd = fast ? true : false;
        Node *temp2 = reverse(lenOdd ? secondHead->next : secondHead);
        Node *temp1 = head;
        while(temp1) {
            if(temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}