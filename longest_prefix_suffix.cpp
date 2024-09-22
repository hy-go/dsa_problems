// Longest Prefix Suffix

/*
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example1:
    Input: str = "abab"
    Output: 2
    Explanation: "ab" is the longest proper prefix and suffix. 

Example2:
    Input: str = "aaaa"
    Output: 3
    Explanation: "aaa" is the longest proper prefix and suffix. 

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
    1 ≤ |str| ≤ 10^6
    str contains lower case English alphabets
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void computeLPS(string word, int n, vector<int> &lps) {
        lps[0] = 0;
        int i = 1, j = 0;
        while(i < n) {
            if(word[i] == word[j]) 
                lps[i++] = ++j;
            else {
                if(j == 0)
                    lps[i++] = 0;
                else 
                    j = lps[j-1];
            }
        }
    }
    
	int lps(string s) {
	    int n = s.length();
	    vector<int> lps(n);
	    computeLPS(s, n, lps);
	    return lps[n-1];
	}
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}