# Stickler Thief II

'''
You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
Determine the maximum amount the thief can steal.
Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

Example1:
    Input: arr[] = [2, 3, 2]
    Output: 3
    Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.

Example2:
    Input: arr[] = [1, 2, 3, 1]
    Output: 4
    Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4

Example3:
    Input: arr[] = [2, 2, 3, 1, 2]
    Output: 5
    Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
    2 ≤ arr.size() ≤ 10^5
    0 ≤ arr[i] ≤ 10^4
'''

class Solution:
    def max_loot(self, houses):
        prev, curr = 0, 0
        for value in houses:
            prev, curr = curr, max(curr, prev + value)
        return curr
    
    def max_value(self, arr):
        return max(self.max_loot(arr[:-1]), self.max_loot(arr[1:]))


class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self):
        arr = [int(i) for i in input().strip().split()]
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = IntArray().Input()
        obj = Solution()
        res = obj.max_value(arr)
        print(res)
        print("~")
