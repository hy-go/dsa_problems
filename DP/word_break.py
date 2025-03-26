# Word Break

"""
You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].
Note: From dictionary[], any word can be taken any number of times and in any order.

Example1:
    Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
    Output: true
    Explanation: s can be breakdown as "i like".

Example2:
    Input: s = "ilikegfg", dictionary = ["i", "like", "man", "india", "gfg"]
    Output: true
    Explanation: s can be breakdown as "i like gfg".

Example3:
    Input: s = "ilikemangoes", dictionary = ["i", "like", "man", "india", "gfg"]
    Output: false
    Explanation: s cannot be formed using dictionary[] words.

Expected Time Complexity:O(n^2)
Expected Space Complexity: O(n)

Constraints:
    1 ≤ s.size() ≤ 3000
    1 ≤ dictionary.size() ≤ 1000
    1 ≤ dictionary[i].size() ≤ 100
"""

from functools import lru_cache

class Solution:
    # Top-Down Approach
    """
    def wordBreak(self, s, dictionary):
        dictionarySet = set(dictionary)
        l = len(max(dictionary, key=len))
        
        @lru_cache(None)
        def isWordBreakPossible(i):
            if i == 0:
                return True
            for j in range(i-1, max(-1, i-l-1), -1):
                if s[j:i] in dictionarySet and isWordBreakPossible(j):
                    return True
            return False
            
        return isWordBreakPossible(len(s))
    """
    
    # Bottom-Up Approach
    def wordBreak(self, s, dictionary):
        dictionarySet = set(dictionary)
        l = len(max(dictionary, key=len))
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        
        for i in range(1, n+1):
            for j in range(i-1, max(-1, i-l-1), -1):
                if dp[j] and s[j:i] in dictionarySet:
                    dp[i] = True
                    break
        
        return dp[n]


if __name__ == '__main__':
    test_case = int(input())

    for _ in range(test_case):
        s = input().strip()
        dictionary = input().strip().split()
        ob = Solution()
        res = ob.wordBreak(s, dictionary)
        if res:
            print("true")
        else:
            print("false")
        print("~")
