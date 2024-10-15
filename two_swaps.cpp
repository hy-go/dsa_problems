// Two Swaps

/*
Given a permutation of some of the first natural numbers in an array arr[], 
determine if the array can be sorted in exactly two swaps. A swap can involve the same pair of indices twice.
Return true if it is possible to sort the array with exactly two swaps, otherwise return false.

Example1:
    Input: arr = [4, 3, 2, 1]
    Output: true
    Explanation: 
        First, swap arr[0] and arr[3]. The array becomes [1, 3, 2, 4]. 
        Then, swap arr[1] and arr[2]. The array becomes [1, 2, 3, 4], which is sorted.
Example2:
    Input: arr = [4, 3, 1, 2]
    Output: false

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
    1 ≤ arr.size() ≤ 10^6
    1 ≤ arr[i] ≤ arr.size()
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void swapOnce(vector<int> &arr, int n) {
        int i = 0;
        while(i < n && arr[i] == i + 1)
            i++;
        if(i == n) return;
        swap(arr[i], arr[arr[i] - 1]);
    }
    
    bool isSorted(vector<int> &arr, int n) {
        int i = 0;
        while(i < n && arr[i] == i + 1)
            i++;
        return i == n;
    }
    
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        swapOnce(arr, n);
        swapOnce(arr, n);
        return isSorted(arr, n);
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
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
