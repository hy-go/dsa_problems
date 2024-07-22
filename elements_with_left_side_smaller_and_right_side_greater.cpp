// Element with left side smaller and right side greater

/*
Given an unsorted array of arr. 
Find the first element in an array such that all of its left elements are smaller and all right elements of its are greater than it.
Note: Return -1 if there is no such element.

Example1:
    Input:
        arr = [4, 2, 5, 7]
    Output: 
        5

Example2:
    Input: 
        arr = [11, 9, 12]   
    Output: 
        -1

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
    3 <= arr.size() <= 10^6
    1 <= arri <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findElement(vector<int> &arr) {
        int n = arr.size();
        int smallest[n], greatest[n], s = INT_MAX, g = INT_MIN;
        for(int i = 0; i < n; ++i) {
            greatest[i] = g;
            if(arr[i] > g)
                g = arr[i];
            smallest[n-i-1] = s;
            if(arr[n-i-1] < s)
                s = arr[n-i-1];
        }
        for(int i = 1; i < n-1; ++i) 
            if(greatest[i] < arr[i] && smallest[i] > arr[i])
                return arr[i];
        return -1;
    }
};

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
        Solution ob;
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}