# Partition Equal Subset Sum

"""
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.
Note: Each element must be in exactly one subset.

Example1:
    Input: arr = [1, 5, 11, 5]
    Output: true
    Explanation: The two parts are [1, 5, 5] and [11].

Example2:
    Input: arr = [1, 3, 5]
    Output: false
    Explanation: This array can never be partitioned into two such parts.

Expected Time Complexity: O(sum(arr) * n)
Expected Auxilliary Space: O(sum(arr) * n)

Constraints:
    1 ≤ arr.size ≤ 100
    1 ≤ arr[i] ≤ 200
"""

import numpy as np

class Solution:
    def equalPartition(self, arr):
        total_sum = sum(arr)
        
        # If total sum is odd, partitioning into equal sum subsets is impossible
        if total_sum % 2:
            return False
        
        target = total_sum // 2
        n = len(arr)

        # Using a 1D DP array to optimize space complexity
        dp = np.zeros(target + 1, dtype=bool)
        dp[0] = True  # Base case: We can always make sum 0

        for num in arr:
            for j in range(target, num - 1, -1):  # Traverse in reverse order to avoid overwriting
                dp[j] = dp[j] or dp[j - num]

        return dp[target]

import sys

input = sys.stdin.readline

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        if ob.equalPartition(arr):
            print("true")
        else:
            print("false")
        print("~")
