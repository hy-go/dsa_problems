// Alternative Sorting

/*
Given an array arr of distinct integers. 
Rearrange the array in such a way that the first element is the largest and the second element is the smallest, 
the third element is the second largest and the fourth element is the second smallest, and so on.

Example1:
    Input: arr[] = [7, 1, 2, 3, 4, 5, 6]
    Output: [7, 1, 6, 2, 5, 3, 4]
    Explanation: The first element is first maximum and second element is first minimum and so on.

Example2:
    Input: arr[] = [1, 6, 9, 4, 3, 7, 8, 2]
    Output: [9, 1, 8, 2, 7, 3, 6, 4]
    Explanation: The first element is first maximum and second element is first minimum and so on.

Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
    1 ≤ arr.size() ≤ 10^5
    1 ≤ arr[i] ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> alternateSort(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), i = 0, j = n-1, k = 0;
        vector<int> res(n);
        while(i < j) {
            res[k++] = arr[j--];
            res[k++] = arr[i++];
        }
        if(i == j)
            res[k] = arr[i];
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
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
