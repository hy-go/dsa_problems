// Reverse Words

/*
Given a String str, reverse the string without reversing its individual words. Words are separated by dots.
Note: The last character has not been '.'. 

Example1:
    Input: str = i.like.this.program.very.much
    Output: much.very.program.this.like.i

Example2:
    Input: str = pqr.mno
    Output: mno.pqr
    
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
    1 <= |str| <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseWords(string str) {
        int i = 0, j = 0, n = str.length();
        auto beginItr = str.begin();
        while(j < n) {
            while(j < n && str[j] != '.')
                j++;
            reverse(beginItr + i, beginItr + j);
            j++;
            i = j;
        } 
        reverse(beginItr + i, beginItr + j);
        reverse(beginItr, beginItr + n);
        return str;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}