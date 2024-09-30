// Merge Two BSTs

/*
Given two BSTs, return elements of merged BSTs in sorted form.
Example1:
    Input:
        BST1:
               5
             /   \
            3     6
           / \
          2   4  
        BST2:
                2
              /   \
             1     3
                    \
                     7
                    /
                   6
    Output: 1 2 2 3 3 4 5 6 6 7

Example2:
    Input:
        BST1:
               12
             /   
            9
           / \    
          6   11
        BST2:
              8
            /  \
           5    10
          /
         2
    Output: 2 5 6 8 9 10 11 12

Expected Time Complexity: O((m+n)*log(m+n))
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
    1 ≤ Number of Nodes, value of nodes ≤ 10^5
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class BSTIterator {
    stack<Node*> s;
    
public:
    BSTIterator(Node *root) {
        while(root) {
            s.push(root);
            root = root->left;        
        }
    }
    
    Node* next() {
        if(s.empty()) return NULL;
        Node *top = s.top();
        s.pop();
        Node *temp = top->right;
        while(temp) {
            s.push(temp);
            temp = temp->left;
        }
        return top;
    }
};

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> mergedList;
        BSTIterator i1 = BSTIterator(root1), i2 = BSTIterator(root2); 
        Node *t1 = i1.next(), *t2 = i2.next(); 
        while(t1 && t2) {
            if(t1->data <= t2->data) {
                mergedList.push_back(t1->data);
                t1 = i1.next();
            } else {
                mergedList.push_back(t2->data);
                t2 = i2.next();
            }
        }
        while(t1) {
            mergedList.push_back(t1->data);
            t1 = i1.next();
        }
        while(t2) {
            mergedList.push_back(t2->data);
            t2 = i2.next();
        }
        return mergedList;
    }
};

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
