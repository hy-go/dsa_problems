// Roof Top

/*
You are given the heights of consecutive buildings. You can move from the roof of a building to the roof of the next adjacent building. You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.

Example1:
    Input: arr[] = [1, 2, 2, 3, 2]
    Output: 1
    Explanation: 1, 2, or 2, 3 are the only consecutive buildings with increasing heights thus maximum number of consecutive steps with an increase in gain in altitude would be 1 in both cases.

Example2:
    Input: arr[] = [1, 2, 3, 4]
    Output: 3
    Explanation: 1 to 2 to 3 to 4 is the jump of length 3 to have a maximum number of buildings with increasing heights, so maximum steps with increasing altitude becomes 3.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 <= arr.size() <= 10^6
    1 <= arr[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxStep(vector<int>& arr) {
        int currJump = 0, maxJump = 0, n = arr.size();
        for(int i = 1; i < n; ++i)
            if(arr[i] > arr[i-1]) 
                currJump++;
            else {
                maxJump = max(maxJump, currJump);
                currJump = 0;
            }
        return max(maxJump, currJump);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}