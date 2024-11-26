// Smallest Positive Missing Number

/*
You are given an integer array arr[]. 
Your task is to find the smallest positive number missing from the array.
Note: Positive number starts from 1. The array can have negative integers too.

Example1:
    Input: arr[] = [2, -3, 4, 1, 1, 7]
    Output: 3
    Explanation: Smallest positive missing number is 3.

Example2:
    Input: arr[] = [5, 3, 2, 5, 1]
    Output: 4
    Explanation: Smallest positive missing number is 4.

Example3:
    Input: arr[] = [-8, 0, -1, -4, -3]
    Output: 1
    Explanation: Smallest positive missing number is 1.

Constraints:  
    1 <= arr.size() <= 10^5
    -10^6 <= arr[i] <= 10^6

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /* Solution 1 (circular sort)
        int missingNumber(vector<int> &arr) {
            int n = arr.size(), i = 0;
            while(i < n) {
                if(arr[i] < 1 || arr[i] > n || arr[i] == i + 1 || arr[arr[i] - 1] == arr[i])
                    i++;
                else
                    swap(arr[i] , arr[arr[i] - 1]);
            }
            for(int i = 0; i < n; ++i)
                if(arr[i] != i + 1)
                    return i + 1;
            return n + 1;
        }
    */ 
    
    // Solution 2
    int missingNumber(vector<int> &arr) {
        int n = arr.size(), i = 0;
        while(i < n) {
            if(arr[i] == 1)
                break;
            i++;
        }
        if(i == n)
            return 1;
        for(i = 0; i < n; ++i)
            if(arr[i] < 1 || arr[i] > n)
                arr[i] = 1;
        for(i = 0; i < n; ++i)
            arr[(arr[i] - 1) % n] += n;
        for(i = 0; i < n; ++i) 
            if(arr[i] <= n)
                return i + 1;        
        return n + 1;
    }
};

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
