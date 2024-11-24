// Kadane's Algorithm

/*
Given an integer array arr[]. 
You need to find and return the maximum sum possible from all the subarrays.

Example1:
    Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
    Output: 11
    Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

Example2:
    Input: arr[] = [-2, -4]
    Output: -2
    Explanation: The subarray {-2} has the largest sum -2.

Example3:
    Input: arr[] = [5, 4, 1, 7, 8]
    Output: 25
    Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

Constraints:
    1 ≤ arr.size() ≤ 10^5
    -10^9 ≤ arr[i] ≤ 10^4

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN, currSum = 0;
        for(int a: arr) {
            currSum += a;
            maxSum = max(maxSum, currSum);
            if(currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
