// Missing and Repeating

/*
Given an unsorted array arr of of positive integers. 
One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. 
Find numbers A and B.

Example1:
    Input: arr[] = [2, 2]
    Output: 2 1
    Explanation: Repeating number is 2 and smallest positive missing number is 1.

Example2:
    Input: arr[] = [1, 3, 3] 
    Output: 3 2
    Explanation: Repeating number is 3 and smallest positive missing number is 2.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    2 ≤ n ≤ 10^5
    1 ≤ arr[i] ≤ n
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int xr = 0;
        for(int i = 1; i <= n; ++i) {
            xr ^= i;
            xr ^= arr[i-1]; 
        }
        int diff = xr&~(xr-1);
        int A = 0, B = 0;
        for(int i = 1; i <= n; ++i) {
            if(diff&i)
                A ^= i;
            else
                B ^= i;
            if(diff&arr[i-1])
                A ^= arr[i-1];
            else
                B ^= arr[i-1];
        }
        for(int i = 0; i < n; ++i) 
            if(arr[i] == A)
                return {A, B};
        return {B, A};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}