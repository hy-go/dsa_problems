// Add Binary Strings

/*
Given two binary strings s1 and s2 consisting of only 0s and 1s. 
Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Example1:
    Input: s1 = "1101", s2 = "111"
    Output: 10100
    Explanation:
         1101
        + 111
        -----
        10100

Example2:
    Input: s1 = "00100", s2 = "010"
    Output: 110
    Explanation: 
          100
        +  10
        -----
          110

Constraints:
  1 ≤ s1.size(), s2.size() ≤ 10^6

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string res = "";
        int i = 0, n1 = s1.length(), n2 = s2.length(), n = max(n1, n2);
        int c = 0, t;
        while(i < n) {
            t = (i < n1 ? s1[i] - 48 : 0) + (i < n2 ? s2[i] - 48 : 0) + c;
            res += t % 2 + 48;
            c = t / 2;
            i++;
        }
        if(c) {
            res += '1';
            n++;
        }
        reverse(res.begin(), res.end());
        i = 0;
        while(i < n && res[i] == '0')
            i++;
        return res.substr(i, n - i);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}
