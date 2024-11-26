// Max Circular Subarray Sum

/*
Given an array of integers arr[] in a circular fashion. 
Find the maximum subarray sum that we can get if we assume the array to be circular.

Example1:
    Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
    Output: 22
    Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

Example2:
    Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
    Output: 23
    Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].

Example3:
    Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
    Output: 52
    Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.

Constraints:
    1 <= arr.size() <= 10^5
    -10^4 <= arr[i] <= 10^4

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN, minSum = INT_MAX, sum1 = 0, sum2 = 0, totalSum = 0;
        for(int a: arr) {
            sum1 += a;
            sum2 += a;
            if(sum1 > maxSum)
                maxSum = sum1;
            if(sum1 < 0)
                sum1 = 0;
            if(sum2 < minSum)
                minSum = sum2;
            if(sum2 > 0)
                sum2 = 0;
            totalSum += a;
        }
        if(maxSum > 0)
            return max(maxSum, totalSum - minSum);
        return maxSum;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}
