// Indexes of Subarray Sum

/*
Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. 
You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. 
You need to find the first subarray whose sum is equal to the target.
Note: If no such array is possible then, return [-1].

Examples:
    Input: arr[] = [1, 2, 3, 7, 5], target = 12
    Output: [2, 4]

    Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
    Output: [1, 5]

    Input: arr[] = [5, 3, 4], target = 2
    Output: [-1]

Constraints:
    1 <= arr.size()<= 10^6
    0 <= arr[i] <= 10^3
    0 <= target <= 10^9

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int i = 0, j = 0, sum = 0, n = arr.size();
        while(sum != target && j < n) {
            sum += arr[j++];
            while(sum > target)
                sum -= arr[i++];
            if(sum == target) 
                return {i + 1, j};
        }
        return {-1};
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
