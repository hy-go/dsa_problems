// Subarray range with given sum

/*
Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

Example1:
    Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
    Output: 3
    Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].

Example2:
    Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
    Output: 1
    Explanation: Subarray with sum 33 is: [20,3,10].

Expected Time Complexity: O(n)
Expected Auxilary Space: O(n)

Constraints:
    1 <= arr.size() <= 10^6
    -10^5 <= arr[i] <= 10^5
    -10^5 <= tar <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int N = arr.size();
        map<int, int> prefixSumCount;
        int currSum = 0;
        int count = 0;
        for(int i = 0; i < N; ++i) {
            currSum += arr[i];
            if(currSum == tar)
                count++;
            count += prefixSumCount[currSum - tar];
            prefixSumCount[currSum]++;
        }
        return count;
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
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
