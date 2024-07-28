// Missing element of AP

/*
Find the missing element from an ordered array arr[], elements of array arr representing an Arithmetic Progression(AP).
Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. Boundary elements (first and last elements) are not missing.

Example1:
    Input: 
        arr[] = [2, 4, 8, 10, 12, 14]
    Output: 
        6
    Explanation: 
        Actual AP should be 2, 4, 6, 8, 10, 12, 14.

Example2:
    Input: 
        arr[] = [1, 6, 11, 16, 21, 31]
    Output: 
        26
    Explanation: 
        Actual AP should be 1, 6, 11, 16, 21, 26, 31. 

Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
    2 <= arr.size() <= 10^5
    0 <=arr[i] <= 2*10^7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size(), s = 1, e = n - 2, m;
        int d = (arr[n-1] - arr[0]) / n;
        while(s <= e) {
            m = (s + e) / 2;
            if(arr[m] == arr[0] + d*m)
                s = m + 1;
            else
                e = m - 1;
        }
        return arr[0] + d*s;
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
        cout << ob.findMissing(arr) << "\n";
    }
    return 0;
}