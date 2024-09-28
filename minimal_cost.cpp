// Minimal Cost

/*
There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: 
Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and 
cost will be |hi-hj| is incurred, where j is the stone to land on. 
Find the minimum possible total cost incurred before the Geek reaches the last stone.

Example1:
    Input: k = 3, arr[]= [10, 30, 40, 50, 20]
    Output: 30
    Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
Example2:
    Input: k = 1, arr[]= [10, 20, 10]
    Output: 20
    Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.

Expected Time Complexity: O(n*k)
Expected Auxilary Space: O(n)

Constraint:
    1<= arr.size() <=10^4
    1 <= k <= 100
    1 <= arr[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n-1; ++i) {
            int m = min(n-1, i+k);
            for(int j = i+1; j <= m; ++j)
                if(dp[j] > dp[i] + abs(arr[i] - arr[j]))
                    dp[j] = dp[i] + abs(arr[i] - arr[j]);
        }
        return dp[n-1];
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
