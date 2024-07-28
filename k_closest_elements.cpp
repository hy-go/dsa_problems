// K closest elements

/*
Given a sorted array of unique elements in increasing order, arr[] of n integers, and a value x. 
Find the K closest elements to x in arr[].
Keep the following points in mind:
    - If x is present in the array, then it need not be considered.
    - If two elements have the same difference as x, the greater element is prioritized.
    - If sufficient elements are not present on the right side, take elements from the left and vice versa.

Example1:
    Input:
        n = 13
        arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56}
        k = 4, x = 35
    Output: 
        39 30 42 45
    Explanation: 
        First closest element to 35 is 39.
        Second closest element to 35 is 30.
        Third closest element to 35 is 42.
        And fourth closest element to 35 is 45.

Example 2:
    Input:
        n = 5
        arr[] = {1, 2, 3, 6, 10}
        k = 3, x = 4
    Output: 
        3 6 2
    Explanation: 
        First closest element is 3. 
        There are two elements 2 and 6 for which the difference with 4 is same i.e. 2.
        So first take greatest number 6 then the lower number 2.

Expected Time Complexity: O(log n + k)
Expected Auxiliary Space: O(k)

Constraints:
    1 ≤ n ≤ 10^5
    1 ≤ k ≤ n
    1 ≤ x ≤ 10^6
    1 ≤ arr[i] ≤ 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = lb - 1, j = lb;
        if(arr[j] == x) j++;
        vector<int> res;
        while((i >= 0 || j < n) && k > 0) {
            if(i < 0) {
                res.push_back(arr[j]);
                j++;
            } else if(j >= n || (x - arr[i] < arr[j] - x)) {
                res.push_back(arr[i]);
                i--;
            } else {
                res.push_back(arr[j]);
                j++;
            }
            k--;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}