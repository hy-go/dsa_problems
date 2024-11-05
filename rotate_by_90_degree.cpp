//Rotate by 90 degree

/*
Given a square mat[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.

Example1:
    Input: mat[][] = [[1 2 3], [4 5 6], [7 8 9]]
    Output:
    7 4 1 
    8 5 2
    9 6 3

Example2:
    Input: mat[][] = [1 2], [3 4]
    Output:
        3 1 
        4 2

Example3:
    Input: mat[][] = [[1]]
    Output: 
        1

Constraints:
    1 ≤ mat.size() ≤ 1000
    1 <= mat[][] <= 100

Expected Time Complexity: O(n^2)
Expected Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &mat) {
    int n = mat.size();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < i; ++j)
            swap(mat[i][j], mat[j][i]);
}

void reverseRows(vector<vector<int>> &mat) {
    int n = mat.size();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n/2; ++j)
            swap(mat[i][j], mat[i][n-1-j]);
}

void rotate(vector<vector<int>> &mat) {
    transpose(mat);
    reverseRows(mat);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
