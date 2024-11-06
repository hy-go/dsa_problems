// Root to leaf paths sum

/*
Given a binary tree, where every node value is a number. Find the sum of all the numbers that are formed from root to leaf paths. The formation of the numbers would be like 10*parent + current (see the examples for more clarification).

Example1:
    Input :      
            6
          /   \
         3     5
       /   \     \
      2     5     4
          /   \
        7      4
    Output: 13997
    Explanation : There are 4 leaves, resulting in leaf path of 632, 6357, 6354, 654 sums to 13997.

Example2:
    Input:    
             10
            /  \
          20    30
        /   \
      40     60 
    Output : 2630
    Explanation: There are 3 leaves, resulting in leaf path of 1240, 1260, 130 sums to 2630.

Example3:
    Input:    
               1
              /
             2                    
    Output : 12
    Explanation: There is 1 leaf, resulting in leaf path of 12.

Constraints:
    1 ≤ number of nodes ≤ 31
    1 ≤ node->data ≤ 100

Expected Time Complexity: O(n)
Expected Space Complexity: O(h)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
        if (i >= ip.size())
            break;
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

class Solution {
  public:
    void _treePathSum(Node *root, int val, int &sum) {
        if(!root)
            return;
        val = val*10 + root->data;
        if(root->left || root->right) {
            _treePathSum(root->left, val, sum);
            _treePathSum(root->right, val, sum);
        }
        else
            sum += val;
    }
    
    int treePathsSum(Node *root) {
        int sum = 0;
        _treePathSum(root, 0, sum);
        return sum;
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.treePathsSum(root);
        cout << endl;
        cout << "~\n";
    }
    return 0;
}
