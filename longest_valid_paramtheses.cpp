// Longest valid Parentheses

/*
Given a string str consisting of opening and closing parenthesis '(' and ')'. 
Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:
    - For every opening parenthesis, there is a closing parenthesis.
    - Opening parenthesis must be closed in the correct order.

Example1:
    Input: ((()
    Output: 2
    Explaination: The longest valid parenthesis substring is "()".
    
Example2:
    Input: )()())
    Output: 4
    Explaination: The longest valid parenthesis substring is "()()".

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
    1 ≤ |str| ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(string& str) {
        stack<int> stk;
        stk.push(-1);
        int n = str.length();
        int maxLen = 0;
        for(int i = 0; i < n; ++i) {
            if(str[i] == '(')
                stk.push(i);
            else {
                stk.pop();
                if(stk.empty()) 
                    stk.push(i);
                else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}