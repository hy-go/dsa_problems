# Stock Buy and Sell – Max 2 Transactions Allowed

"""
In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).

Example1:
    Input: prices[] = [10, 22, 5, 75, 65, 80]
    Output: 87
    Explanation: 
	Trader will buy at 10 and sells at 22. 
	Profit earned in 1st transaction = 22 - 10 = 12. 
	Then he buys at 5 and sell at 80. 
	Profit earned in 2nd transaction = 80 - 5 = 75. 
	Total profit earned = 12 + 75 = 87. 

    Input: prices[] = [2, 30, 15, 10, 8, 25, 80]
    Output: 100
    Explanation: 
	Trader will buy at 2 and sells at 30. 
	Profit earned in 1st transaction = 30 - 2 = 28. 
	Then he buys at 8 and sell at 80. 
	Profit earned in 2nd transaction = 80 - 8 = 72. 
	Total profit earned = 28 + 72 = 100.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
    1 <= prices.size() <= 10^5
    1 <= prices[i] <= 10^5
"""

import math

class Solution:
    def maxProfit(self, prices):
        prev = [-2**17, 0, -2**17, 0]
        max_profit = 0  
        
        for price in prices:
            curr = [
                max(prev[0], -price),        # First buy
                max(prev[1], prev[0] + price),  # First sell
                max(prev[2], prev[1] - price),  # Second buy
                max(prev[3], prev[2] + price)   # Second sell
            ]
            max_profit = max(max_profit, curr[3])
            prev = curr  # Update prev for next iteration

        return max_profit

def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxProfit(arr))
        t -= 1
        print("~")

if __name__ == "__main__":
    main()

