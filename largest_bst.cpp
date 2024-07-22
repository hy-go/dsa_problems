// 22nd July 2024
// Largest BST

/*
Given a binary tree. 
Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Example1:
    Input: 
         1
        / \
        4  4              
       / \ 
      6   8
    Output: 
        1 
    Explanation: 
        There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.
        
Example2:
    Input: 
          6
       /    \
      6      2              
       \    / \
        2  1   3
    Output: 
        3
    Explanation: 
        The following sub-tree is a BST of size 3:  
            2
           / \
          1   3

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
    1 ≤ Number of nodes ≤ 10^5
    1 ≤ Data of a node ≤ 10^6
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution{
    public:
    vector<int> _largestBst(Node *root) {
        if(!root) return {0, INT_MAX, INT_MIN};
        vector<int> left = _largestBst(root->left), right = _largestBst(root->right);
        if(left[2] < root->data && root->data < right[1]) 
            return vector<int>{left[0] + right[0] + 1, min(root->data, left[1]), max(root->data, right[2])};
        return vector<int>{max(left[0], right[0]), INT_MIN, INT_MAX};
    }
    
    int largestBst(Node *root) {
        return _largestBst(root)[0];
    }
};

int main() {   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}