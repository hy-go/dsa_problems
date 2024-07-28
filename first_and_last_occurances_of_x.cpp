// First and last occurrences of x

/*
Given an element x and a sorted array, arr[], find the indices of first and last occurrences of the x's in the array.
Note: If the number x is not found in the array, return '-1' as an array.

Example1:
    Input: x = 3, arr[] = [1, 3, 3, 4]
    Output: [1, 2]
    Explanation: For the above array, the first occurrence of X = 3 is at index = 1 and the last occurrence is at index = 2.

Example2:
    Input: x = 5, arr[] = [1, 2, 3, 4]
    Output: [-1]
    Explanation: As 5 is not present in the array, so the answer is -1.

Expected Time Complexity: O(logn)
Expected Auxillary Space: O(1)

Constraints: 
    1 <= arr.size() <= 10^5 
    0 <= arr[i], x <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(arr[lb] != x)
            return {-1};
        return {lb, ub-1};
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); 
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(x, arr);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}