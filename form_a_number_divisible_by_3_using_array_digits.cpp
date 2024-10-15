// Form a number divisible by 3 using array digits

/*
You will be given an array arr of integers of length N. 
You can construct an integer from two integers by treating the integers as strings, and then concatenating them. 
For example, 19 and 4 can be used to construct 194 and 419.
The task is to find whether it’s possible to construct an integer using all the digits of these numbers such that it would be divisible by 3.
If it is possible then print 1 and if not print 0.

Example1:
    Input: N = 3, arr = {40, 50, 90}
    Output: 1
    Explanation: One such number is 405090.

Example2:
    Input: N = 2, arr = {1, 4}
    Output: 0
    Explanation: The numbers we can form are 14 and 41. But neither of them are divisible by 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        int rem = 0;
        for(int i = 0; i < N; ++i) {
            rem = (rem + arr[i]) % 3;
        }
        return rem == 0;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
