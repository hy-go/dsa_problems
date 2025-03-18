// Partition Equal Subset Sum

/*
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.
Note: Each element must be in exactly one subset.

Example1:
    Input: arr = [1, 5, 11, 5]
    Output: true
    Explanation: The two parts are [1, 5, 5] and [11].

Example2:
    Input: arr = [1, 3, 5]
    Output: false
    Explanation: This array can never be partitioned into two such parts.

Expected Time Complexity: O(sum(arr) * n)
Expected Auxilliary Space: O(sum(arr) * n)

Constraints:
    1 ≤ arr.size ≤ 100
    1 ≤ arr[i] ≤ 200
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(totalSum % 2)
            return false;
        int subArrSumReq = totalSum/2;
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(subArrSumReq + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for(int j = 1; j <= subArrSumReq; ++j) {
                if(arr[i - 1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        for(int i = 1; i <= n; ++i)
            if(dp[i][subArrSumReq])
                return true;
        return false;
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
