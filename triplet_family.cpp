// Triplet Family

/*
Given an array arr of integers.
Find whether three numbers are such that the sum of two elements equals the third element.

Example1:
    Input: arr[] = [1, 2, 3, 4, 5]
    Output: true

Example2:
    Input: arr[] = [5, 3, 4]
    Output: false

Expected Time Complexity: O(n2)
Expected Auxilary Space: O(1)

Constraints:
    1 <= arr.size() <= 10^3
    0 <= arr[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;
            while(j < k) {
                if(arr[i] == arr[j] + arr[k])
                    return true;
                else if(arr[i] > arr[j] + arr[k])
                    k--;
                else
                    j++;
            }
        }
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
