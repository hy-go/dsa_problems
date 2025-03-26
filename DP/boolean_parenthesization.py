# Boolean Parenthesization

"""
You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.

Examples:

Input: s = "T|T&F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).

Constraints:
1 ≤ |s| ≤ 100 
"""

from functools import lru_cache

class Solution:
    def countWays(self, s: str) -> int:
        # return self.possibleWays(s, 0, len(s) - 1, True)
    	return self.possibleWays(s)
    	
    # Top-Down Approach
    @lru_cache(None)
    def possibleWays(self, s: str, i: int, j: int, expect_true: bool) -> int:
        if i == j:
            return int((s[i] == 'T') == expect_true)

        total_ways = 0
        for k in range(i + 1, j, 2):
            left_true = self.possibleWays(s, i, k - 1, True)
            left_false = self.possibleWays(s, i, k - 1, False)
            right_true = self.possibleWays(s, k + 1, j, True)
            right_false = self.possibleWays(s, k + 1, j, False)
            tt = left_true * right_true
            tf = left_true * right_false
            ft = left_false * right_true
            ff = left_false * right_false
            if s[k] == '|':
                total_ways += (tt + ft + tf) if expect_true else ff
            elif s[k] == '&':
                total_ways += tt if expect_true else (tf + ft + ff)
            elif s[k] == '^':
                total_ways += (tf + ft) if expect_true else (tt + ff)

        return total_ways
        

    # Bottom-Up Approach
    def possibleWays(self, s: str) -> int:
        n = len(s)
        dp = [[[-1, -1] for _ in range(n)] for _ in range(n)]
    
        for i in range(0, n, 2):
            dp[i][i][0] = int(s[i] == 'F')
            dp[i][i][1] = int(s[i] == 'T')
        
        for length in range(3, n+1, 2):
            for i in range(0, n - length + 1, 2):
                j = i + length - 1
                total_ways_true = 0
                total_ways_false = 0
                for k in range(i+1, j, 2):
                    left_true = dp[i][k-1][1]
                    left_false = dp[i][k-1][0]
                    right_true = dp[k+1][j][1]
                    right_false = dp[k+1][j][0]
                    tt = left_true * right_true
                    tf = left_true * right_false
                    ft = left_false * right_true
                    ff = left_false * right_false
                    if s[k] == '|':
                        total_ways_true += tt + ft + tf 
                        total_ways_false += ff
                    elif s[k] == '&':
                        total_ways_true += tt
                        total_ways_false += tf + ft + ff
                    elif s[k] == '^':
                        total_ways_true += tf + ft 
                        total_ways_false += tt + ff
                dp[i][j][1] = total_ways_true
                dp[i][j][0] = total_ways_false
        return dp[0][n-1][1]
    
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input().strip()
        print(Solution().countWays(s))
        print("~")
