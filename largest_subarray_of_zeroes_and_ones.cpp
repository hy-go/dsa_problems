// Largest subarray of 0's and 1's

/*
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Example 1:
    Input:
        N = 4
        A[] = {0,1,0,1}
    Output: 4
    Explanation: 
        The array from index [0...3] contains equal number of 0's and 1's.
        Thus maximum length of subarray having equal number of 0's and 1's is 4.

Example 2:
    Input:
        N = 5
        A[] = {0,0,1,0,0}
    Output: 2

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
    1 <= N <= 10^5
    0 <= A[] <= 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxLen(int arr[], int N) {
        // creating a hashmap to store the prefixSum
        map<int, int> prefixSum;
        
        // to handle the case where prefix sum becomes 0,
        // then the largest length of subarray becomes current traversed array
        // it will be having equal number of 0s and 1s
        prefixSum[0] = -1; 
        
        // for each element of the arr,
        // if element is 0, then we deduct -1 from the sum else we add 1
        // now we check if sum obtained already formed or not,
        // if found, then we update maxLen if found to be maximum
        // else we add sum with index to hash map
        int sum = 0;
        int maxLen = 0;
        for(int i = 0; i < N; ++i) {
            sum += arr[i] == 0 ? -1 : 1;
            
            if(prefixSum.find(sum) != prefixSum.end()) {
                maxLen = max(maxLen, i - prefixSum[sum]);
            } else 
                prefixSum[sum] = i;
        }
        return maxLen;
    }
};

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
