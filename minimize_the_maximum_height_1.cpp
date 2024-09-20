// Minimize the Maximum Height 1

/*
Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
Note: Assume that height of the tower can be negative.

Example 1:
    Input:
        K = 2, N = 4
        Arr[] = {1, 5, 8, 10}
    Output:
        5
    Explanation:
        The array can be modified as {3, 3, 6, 8}. 
        The difference between the largest and the smallest is 8-3 = 5.

Example 2:
    Input:
        K = 3, N = 5
        Arr[] = {3, 9, 12, 16, 20}
    Output:
        11
    Explanation:
        The array can be modified as {6, 12, 9, 13, 17}. 
        The difference between the largest and the smallest is 17-6 = 11. 

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)

Constraints:
    1 ≤ K ≤ 10^4
    1 ≤ N ≤ 10^5
    1 ≤ Arr[i] ≤ 10^5
*/ 

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        if (n == 1) return 0;  
        
        sort(arr, arr + n);

        int minDiff = arr[n-1] - arr[0];
        for (int i = 1; i < n; ++i) {
            int minValue = min(arr[0] + k, arr[i] - k); 
            int maxValue = max(arr[n-1] - k, arr[i-1] + k); 
            
            minDiff = std::min(minDiff, maxValue - minValue);
        }
        return minDiff;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}