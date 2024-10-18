// Single Number

/*
Given an array arr[] of positive integers where every element appears even times except for one. 
Find that number occurring an odd number of times.

Example1:
    Input: arr[] = [1, 1, 2, 2, 2]
    Output: 2

Example2:
    Input: arr[] = [8, 8, 7, 7, 6, 6, 1]
    Output: 1

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 ≤ arr.size() ≤ 10^6
    0 ≤ arri ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int xr = 0;
        for(int a: arr)
            xr ^= a;
        return xr;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
