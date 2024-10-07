// Largest Pair Sum

/*
Find the largest pair sum in an array of distinct integers.

Example1:
    Input: arr[] = [12, 34, 10, 6, 40]
    Output: 74
    Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74.
Example2:
    Input: arr[] = [10, 20, 30]
    Output: 50
    Explanation: 20 + 30 = 50.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    2 ≤ arr.size() ≤ 10^6
    0 ≤ arr[i] ≤ 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int l = -1, sl = -1;
        for(int a: arr) {
            if(a >= l) {
                sl = l;
                l = a;
            }
            else if(a > sl)
                sl = a;
        } 
        return l + sl;
    }
};

int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
