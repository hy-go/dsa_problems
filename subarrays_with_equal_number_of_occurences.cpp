// Sub-arrays with equal number of occurances

/*
Given an array arr[] and two integers say, x and y, 
find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.

Example1:
    Input: arr[] = [1, 2, 1] , x= 1 , y = 2
    Output: 2
    Explanation: 
        The possible sub-arrays have same equal number of occurrences of x and y are:
            [1, 2], x and y have same occurrence(1).
            [2, 1], x and y have same occurrence(1).

Example2:
    Input: arr[] = [1, 2, 1] , x = 4 , y = 6
    Output: 6
    Explanation: 
        The possible sub-arrays have same equal number of occurrences of x and y are:
            [1], x and y have same occurrence(0).
            [2], x and y have same occurrence(0).
            [1], x and y have same occurrence(0).
            [1, 2], x and y have same occurrence(0).
            [2, 1], x and y have same occurrence(0).
            [1, 2, 1], x and y have same occurrence(0).

Example3:
    Input: arr[] = [1, 2, 1] , x= 1 , y = 4
    Output: 1
    Explanation: The possible sub-array have same equal number of occurrences of x and y is: [2], x and y have same occurrence(0)

Constraints: 
    1 <= arr.size() <= 10^6
    1 <= arr[i], x, y<=10^6

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
*/

/*
Solution Explanation:

1. Brute Force Apporach: 
        For each sub-array (using take/not-take) method, count the occurances of x and y while creating the sub-arrays, 
        and also keep count of sub-arrays with equal number of x and y occurances.
        TC: O(n^2)
        SC: O(1)

2. Using Map and Hand-Shake Alogrithm:
      Traverse the array while keeping the count of x and y,
      while traversing, for each index, find the difference between x and y count, and store the difference.
     Instead of storing the difference, we can also directly add this difference to a map, that maps difference to count of prefix sub-arrays.
     Now, set res as map[0] (i.e. count of prefix sub-arrrays with difference as 0)
     Then for each possible difference, add (diff*(diff-1))/2 to res.
     Return res.
     TC: O(n)
     SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int n = arr.size(), i = 0;
        int countX = 0, countY = 0, diff[n];
        for(int a: arr) {
            if(a == x)
                countX++;
            else if(a == y)
                countY++;
            diff[i++] = countX - countY;
        }
        map<int, int> mp;
        for(int i = 0; i < n; ++i)
            mp[diff[i]]++;
        int res = mp[0];
        for(auto p: mp) {
            if(p.second != 0)
                res += (abs(p.second) * (abs(p.second) - 1)) / 2;
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
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
