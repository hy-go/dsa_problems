// Minimize the heights 1

/*
Given a positive integer k and an array arr[] denoting heights of towers, 
you have to modify the height of each tower either by increasing or decreasing them by k only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Example1:
    Input: k = 2, arr[] = [1, 5, 8, 10]
    Output: 5
    Explanation: The array can be modified as [3, 3, 6, 8]. The difference between the largest and the smallest is 8 - 3 = 5.

Example2:
    Input: k = 3, arr[] = [3, 9, 12, 16, 20]
    Output: 11
    Explanation: The array can be modified as [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17 - 6 = 11. 

Constraints:
    1 ≤ k ≤ 10^4
    1 ≤ number of towers ≤ 10^5
    0 ≤ arr[i] ≤ 10^5

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0;  
        
        sort(arr.begin(), arr.end());

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
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
