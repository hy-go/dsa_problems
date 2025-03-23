#Total Decoding Messages

'''
A message containing letters A-Z is being encoded to numbers using the following mapping:
    'A' -> 1, 'B' -> 2, ..., 'Z' -> 26
You are given a string digits. You have to determine the total number of ways that message can be decoded.

Example1:
    Input: digits = "123"
    Output: 3
    Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).

Example2:
    Input: digits = "90"
    Output: 0
    Explanation: "90" cannot be decoded, as it's an invalid string and we cannot decode '0'.

Example3:
    Input: digits = "05"
    Output: 0
    Explanation: "05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), the string is not a valid encoding message.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
    1 ≤ digits.size() ≤ 10^3
'''

import sys

sys.setrecursionlimit(10**6)
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        digits = input()
        ob = Solution()
        ans = ob.countWays(digits)
        print(ans)
        print("~")

class Solution:
    def countWays(self, digits: str) -> int:
        if digits[0] == '0': 
            return 0 # if very first digit is '0', then decoding is not possible
        prevWays, currWays = 1, 1
        for i in range(1, len(digits)):
            singleDigitWays = curr if digits[i] != '0' else temp = curr
            doubleDigit = int(digits[i - 1 : i + 1])
            doubleDigitWays = prevWays if 10 <= doubleDigit <= 26 else 0
            prevWays, currWays = currWays, singleDigitWays + doubleDigitWays
        return currWays
