// Split the Array

/*
Given an array arr[] of integers, the task is to count the number of ways to split given array elements into two disjoint groups such that the XOR of elements of each group is equal.
Note: The answer could be very large so print it by doing modulo with 109 + 7. 

Example1:
    Input : arr[] = [1, 2, 3]
    Output : 3
    Explanation: {(1),(2, 3)}, {(2),(1, 3)}, {(3),(1, 2)} are three ways with equal XOR value of two groups.

Example2:
    Input : arr[] = [5, 2, 3, 2]
    Output : 0
    Explanation: No way to split into  two groups whose XOR is equal.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
    1<=arr.size()<=10^6
    1<=arr[i]<=10^6
*/

/*
Explaination:
    A ^ A = 0
    This means, if XOR of two sub-groups of the array are equal, then their XOR must be 0.
    Therefore, if XOR of all the elements of the array is not equal to 0, then no such sub-group exist in the arraym whose XOR are equal.

    Now, if XOR of all elements of array is 0, then we can take any sub-groups of the array, there XOR will be equal, because then only XOR of all elements will be 0.
    Hence, we just have to return total number of sub-groups possible, i.e. 2^n.
    But since, sub-group must contain atleast 1 element, therefore 2 possibilities {0, n} and {n, 0} of sub-groups are to be deducted from the result.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int xr = 0;
        for(int a: arr)
            xr ^= a;
        if(xr != 0)
            return 0;
        int mod = 1e9+7;
        return ((1LL<<arr.size())-2)/2 % mod;
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
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}
