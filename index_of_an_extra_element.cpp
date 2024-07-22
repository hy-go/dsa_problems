// Index of an Extra Element

/*
You have given two sorted arrays arr1[] & arr2[] of distinct elements. 
The first array has one element extra added in between. 
Return the index of the extra element.
Note: 0-based indexing is followed.

Example1:
    Input: 
        n = 7
        arr1[] = {2,4,6,8,9,10,12}
        arr2[] = {2,4,6,8,10,12}
    Output: 
        4
    
Example2:
    Input:
        n = 6
        arr1[] = {3,5,7,8,11,13}
        arr2[] = {3,5,7,11,13}
    Output: 
        3

Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
    1<=n<=10^5
    1<=arr1[i],arr2[i]<=10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int s = 0, e = n - 1, m;
        while(s <= e) {
            m = (s + e) / 2;
            if(arr1[m] == arr2[m])
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}