// Swap and Maximize

/*
Given an array arr[ ] of positive elements. 
Consider the array as a circular array, meaning the element after the last element is the first element of the array. 
The task is to find the maximum sum of the absolute differences between consecutive elements with shuffling of array elements allowed 
i.e. shuffle the array elements and make [a1..an] such order that  |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1| is maximized.

Example1:
    Input: arr[] = [4, 2, 1, 8]
    Output: 18
    Explanation: After Shuffling, we get [1, 8, 2, 4]. Sum of absolute difference between consecutive elements after rearrangement = |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 7 + 6 + 2 + 3 = 18.

Example2:
    Input: arr[] = [10, 12]
    Output: 4
    Explanation: No need of rearrangement. Sum of absolute difference between consecutive elements = |10 - 12| + |12 - 10| = 2 + 2 = 4.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(1)
  
Constraints:
    2 ≤ arr.size()≤ 10^5
    1 <= arr[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), i = 0, j = n - 1;
        long long sum = 0;
        while(i < j) {
            sum += arr[j] - arr[i];
            i++;
            if(i == j)
                break;
            sum += arr[j] - arr[i];
            j--;
        }
        return sum + arr[j] - arr[0];
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
