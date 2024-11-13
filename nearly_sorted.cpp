// Nearly Sorted

/*
Given an array arr[], where each element is at most k away from its target position, 
you need to sort the array optimally.

Example1:
    Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
    Output: [2, 3, 5, 6, 8, 9, 10]
    Explanation: The sorted array will be 2 3 5 6 8 9 10

Example2:
    Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
    Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10

Constraints:
    1 ≤ arr.size() ≤ 10^6
    1 ≤ k < arr.size()
    1 ≤ arr_i ≤ 10^6

Time Complexity: O(n log k)
Auxiliary Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; ++i)
            pq.push(arr[i]);
        for(int i = k; i < n; ++i) {
            pq.push(arr[i]);
            arr[i - k] = pq.top();
            pq.pop();
        }
        for(int i = n - k; i < n; ++i) {
            arr[i] = pq.top();
            pq.pop();
        }
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
