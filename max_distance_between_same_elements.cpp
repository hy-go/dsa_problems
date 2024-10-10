// Max distance between same elements

/*
Given an array arr[] with repeated elements, the task is to find the maximum distance between two occurrences of an element.
Note: You may assume that every input array has repetitions.

Example1:
    Input: arr = [1, 1, 2, 2, 2, 1]
    Output: 5
    Explanation: distance for 1 is: 5-0 = 5, distance for 2 is : 4-2 = 2, So max distance is 5.

Example2:
    Input: arr = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]
    Output: 10
    Explanation: maximum distance for 2 is 11-1 = 10, maximum distance for 1 is 4-2 = 2 ,maximum distance for 4 is 10-5 = 5, So max distance is 10.

Expected Time Complexity :  O(n)
Expected Auxilliary Space : O(n)

Constraints:
    1 <= arr.size() <= 10^6
    1 <= arr[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        map<int, int> firstOccPos;
        int maxDist = 0, n = arr.size();
        for(int i = 0; i < n; ++i)
            if(firstOccPos.find(arr[i]) != firstOccPos.end()) 
                maxDist = max(maxDist, i - firstOccPos[arr[i]]);
            else
                firstOccPos[arr[i]] = i;
        return maxDist;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
