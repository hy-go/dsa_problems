// Linked List Matrix
/*
Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Expected Time Complexity: O(n^2)
Expected Space Complexity: O(n^2)

Constraints:
    1 <= mat.size() <=15
    1 <= mat[i][j] <=10^4  
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        vector<vector<Node*>> ptrMat(n, vector<Node*>(n, NULL));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ptrMat[i][j] = new Node(mat[i][j]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(j < n - 1)
                    ptrMat[i][j]->right = ptrMat[i][j+1];
                if(i < n - 1)
                    ptrMat[i][j]->down = ptrMat[i+1][j];
            }
        return ptrMat[0][0];
    }
};

class Solution2 {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        Node *currDummyHead, *downNode = NULL;
        for(int i = n-1; i >= 0; --i) {
            currDummyHead = new Node(-1);
            Node *temp = currDummyHead;
            for(int j = 0; j < n; ++j) {
                temp->right = new Node(mat[i][j]);
                temp = temp->right;
                temp->down = downNode;
                if(downNode)
                    downNode = downNode->right;
            }
            downNode = currDummyHead->right;
        }
        return currDummyHead->right;
    }
};

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}
