# Stickler Thief

'''
Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
Determine the maximum amount he can loot.

Example1:
    Input: arr[] = [6, 5, 5, 7, 4]
    Output: 15
    Explanation: Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6 + 5 + 4 = 15.

Example2:
    Input: arr[] = [1, 5, 3]
    Output: 5
    Explanation: Loot only 2nd house and get maximum amount of 5.

Example3:
    Input: arr[] = [4, 4, 4, 4]
    Output: 8
    Explanation: The optimal choice is to loot every alternate house. Looting the 1st and 3rd houses, or the 2nd and 4th, both give a maximum total of 4 + 4 = 8.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
    1 ≤ arr.size() ≤ 10^5
    1 ≤ arr[i] ≤ 10^4
'''

import sys
sys.setrecursionlimit(10**6)

class Solution:  
    def findMaxSum(self, houses: list[int]) -> int:
        if not houses:
            return 0
        prev_loot, curr_loot = 0, 0
        for money in houses:
            new_loot = max(curr_loot, prev_loot + money)
            prev_loot, curr_loot = curr_loot, new_loot
        return curr_loot

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        a = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.findMaxSum(a))
        print("~")
