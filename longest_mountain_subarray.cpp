// Longest Mountain Subarray 

/*
You are given an array of 'N' integers denoting the heights of the mountains. 
You need to find the length of the longest subarray which has the shape of a mountain.
A mountain subarray is defined as a subarray which consists of elements that are initially in ascending order until a peak element is reached 
and beyond the peak element all other elements of the subarray are in decreasing order.

Example1:
    Input: [1 3 1 4]
    Output: 3
    Explanation: The longest mountain subarray would be 3. This is because the longest mountain is  [1 3 1] having length 3.

Example2:
    Input: 1 3 1 4 3 1
    Output: 4
    Explanation: The longest mountain would be of length: 4 i.e. 1 4 3 1.

Constraints:
    1 ≤ N ≤ 10^5
    1 ≤ Ai ≤ 10^9

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/

#include <bits/stdc++.h> 
using namespace std;

int longestMountain(int *arr, int n) {
    int prev[n] = {0}, next[n] = {0};
    for(int i = 1; i < n; ++i) 
        if(arr[i-1] < arr[i])
            prev[i] = prev[i-1] + 1;
    for(int i = n-2; i >= 0; --i)
        if(arr[i] > arr[i+1])
            next[i] = next[i+1] + 1;
    int mx = 0;
    for(int i = 1; i < n; ++i)
        if(prev[i] != 0 && next[i] != 0)
            mx = max(mx, prev[i] + next[i] + 1);
    return mx;
}