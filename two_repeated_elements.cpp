// Two Repeated Elements

/*
You are given an integer n and an integer array arr of size n+2. 
All elements of the array are in the range from 1 to n. 
Also, all elements occur once except two numbers which occur twice. 
Find the two repeating numbers.

Note: 
    Return the numbers in their order of appearing twice. 
    So, if x and y are repeating numbers, and x's second appearance comes before the second appearance of y, 
    then the order should be (x, y).

Example1:
    Input: n = 4, arr[] = [1, 2, 1, 3, 4, 3]
    Output: 1 3

Example2:
    Input: n = 2, arr[] = [1, 2, 2, 1]
    Output: 2 1

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1). 

Constraints:
    2 ≤ n ≤ 10^5
    1 ≤ arr[i] ≤ n
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoRepeated(int n, int arr[]) {
        int xor1 = 0;
        for(int i = 0; i < n + 2; ++i)
            xor1 ^= ((i + 1) ^ arr[i]);
        xor1 ^= (n + 1) ^ (n + 2);
        int diffBit = xor1 & ~(xor1 - 1);
        int A = 0, B = 0;
        for(int i = 0; i < n + 2; ++i) {
            if(i < n) {
                if(diffBit & (i + 1))
                    A ^= (i + 1);
                else
                    B ^= (i + 1);
            }
            if(arr[i] & diffBit)
                A ^= arr[i];
            else
                B ^= arr[i];
        }
        int ACount = 0, BCount = 0;
        for(int i = 0; i < n + 2; ++i) 
            if(arr[i] == A) {
                if(ACount == 1)
                    return {A, B};
                ACount++;
            }
            else if(arr[i] == B) {
                if(BCount == 1)
                    return {B, A};
                BCount++;
            }
    }
};

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int arr[n + 2];

        for (int i = 0; i < n + 2; i++)
            cin >> arr[i];

        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(n, arr);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}