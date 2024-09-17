// Minimize the Maximum Height 2

/*
Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.
    - Increase the height of the tower by K
    - Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.
Note: 
    It is compulsory to increase or decrease the height by K for each tower. 
    After the operation, the resultant array should not contain any negative integers.

Example 1:
    Input:
        K = 2, N = 4
        arr[] = {1, 5, 8, 10}
    Output:
        5
    Explanation:
        The array can be modified as {3, 3, 6, 8}. 
        The difference between the largest and the smallest is 8-3 = 5.

Example 2:
    Input:
        K = 3, N = 5
        arr[] = {3, 9, 12, 16, 20}
    Output:
        11
    Explanation:
        The array can be modified as {6, 12, 9, 13, 17}. 
        The difference between the largest and the smallest is 17-6 = 11. 

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)

Constraints:
    1 ≤ K ≤ 10^7
    1 ≤ N ≤ 10^5
    1 ≤ arr[i] ≤ 10^7
*/ 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;  
        
        sort(arr.begin(), arr.end());

        int minDiff = arr[n-1] - arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] < k) continue; 
            
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
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}