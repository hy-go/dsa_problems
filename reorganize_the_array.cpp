// Reorganize The Array

/*
Given an array of elements arr[] with indices ranging from 0 to arr.size() - 1, your task is to write a program that rearranges the elements of the array such that arr[i] = i. 
If an element i is not present in the array, -1 should be placed at the corresponding index.

Example1:
    Input: arr[] = [-1, -1, 6, 1, 9, 3, 2, -1, 4, -1]
    Output: [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

Example2:
    Input: arr[] = [2, 0, 1]
    Output: [0, 1, 2]
    
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
    0 ≤ arr.size() ≤ 10^5
    -1 ≤ arr[i] ≤ arr.size()-1
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> rearrange(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; ++i) 
            while(arr[i] != -1 && arr[i] != i) {
                if(arr[arr[i]] == arr[i])
                    arr[i] = -1;
                else 
                    swap(arr[i], arr[arr[i]]);
            }
        return arr;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
