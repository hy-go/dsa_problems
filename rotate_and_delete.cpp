// Rotate and Delete

/*
Given an array arr integers. Do the following operation until a single element left. 
For every kth operation:
    - Right, rotate the vector clockwise by 1.
    - Delete the kth element from the last.
Now, find the element which is left at last.

Example1:
    Input: arr = [1, 2, 3, 4, 5, 6]
    Output: 3
    Explanation: 
        Rotate the vector clockwise i.e. after rotation the vector arr = [6, 1, 2, 3, 4, 5] 
        and delete the last element that is 5 that will be arr = [6, 1, 2, 3, 4]. 
        Similarly, the output will be 3.

Example2:
    Input: arr = [1, 2, 3, 4]
    Output: 2
    Explanation: 
        Rotate the vector clockwise i.e. after rotation the vector arr = [4, 1, 2, 3] 
        and delete the last element that is 3 that will be arr = [4, 1, 2]. 
        Similarly, the output will be 2.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 <= arr.size() <= 10^5
    1 <= arr[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int n = arr.size(), i = n, j = n - 2, k = 2;
        if(n == 1)
            return arr[0];
        while(true) {
            arr[j] = -arr[j];
            i--;
            if(i <= n / 2)
                break;
            k = 3;
            while(k) {
                j = (j - 1 + n) % n;
                if(arr[j % n] > 0) 
                    k--;
            }
        }
        
        while(arr[j] < 0)
            if(n % 2) 
                j = (j + 1) % n;
            else
                j = (j - 1 + n) % n;
        return arr[j];
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
