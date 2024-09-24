// Smallest window in a string containing all the characters of another string

/*
Given two strings s and p. 
Find the smallest window in the string s consisting of all the characters(including duplicates) of the string p.
Return "-1" in case there is no such window present. 
In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Example1:
    Input: s = "timetopractice", p = "toc"
    Output: toprac
    Explanation: "toprac" is the smallest substring in which "toc" can be found.

Example2:
    Input: s = "zoomlazapzo", p = "oza"
    Output: apzo
    Explanation: "apzo" is the smallest substring in which "oza" can be found.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(n), n = len(p)

Constraints: 
1 ≤ |s|, |p| ≤ 10^5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string smallestWindow (string str, string pat) {
        int s = str.length(), p = pat.length();
        int patFreq[26] = {0}, freq[26] = {0};
        int distinct = 0, count = 0;
        int start = 0, end = 0;
        int minLen = INT_MAX, minStart = -1;
        for(char c: pat) {
            patFreq[c - 'a']++;
            if(patFreq[c - 'a'] == 1)
                distinct++;
        }
        while(end < s) {
            freq[str[end] - 'a']++;
            if(freq[str[end] - 'a'] == patFreq[str[end] - 'a'])
                count++;
            while(count == distinct) {
                if(minLen > end - start + 1) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                freq[str[start] - 'a']--;
                if(freq[str[start] - 'a'] == patFreq[str[start] - 'a'] - 1)
                    count--;
                start++;
            }
            end++;
        }
        return minStart == -1 ? "-1" : str.substr(minStart, minLen);
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}