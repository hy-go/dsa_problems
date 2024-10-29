// Pairs with difference k

/*
Given an array arr[] of positive integers. 
Find the number of pairs of integers whose difference equals a given number k.
Note: (a, b) and (b, a) are considered the same. 
Also, the same numbers at different indices are considered different.

Example1:
    Input: arr[] = [1, 5, 3, 4, 2], k = 3
    Output: 2
    Explanation: There are 2 pairs with difference 3,the pairs are {1, 4} and {5, 2} 

Example2:
    Input: arr[] = [8, 12, 16, 4, 0, 20], k = 4
    Output: 5
    Explanation: There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, {8, 12}, {12, 16} and {16, 20}.

Constraints:
    1 <= arr.size() <= 10^6
    1 <= k <= 10^6
    1 <= arri <= 10^6
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        map<int, int> freq;
        int res = 0;
        for(int a: arr) {
            freq[a]++;
            if(freq.find(a + k) != freq.end())
                res += freq[a + k];
            if(freq.find(a - k) != freq.end())
                res += freq[a - k];
        }
        return res;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
