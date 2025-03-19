// Stock Buy and Sell – Max 2 Transactions Allowed

/*
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
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int totalDays = prices.size();
        vector<vector<int>> dp(totalDays + 1, vector<int>(4, 0));
        dp[0][0] = INT_MIN;
        dp[0][1] = 0;
        dp[0][2] = INT_MIN;
        dp[0][3] = 0;
        int maxProfit = -1;
        for(int i = 1; i <= totalDays; ++i) {
            dp[i][0] = max(dp[i-1][0], -prices[i - 1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i-1]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i-1]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i-1]);
            maxProfit = max(maxProfit, dp[i][3]);
        }
        return maxProfit;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
