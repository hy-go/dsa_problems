// Facing the sun

/*
Given an array height representing the heights of buildings. 
You have to count the buildings that will see the sunrise (Assume the sun rises on the side of the array starting point).
Note: The height of the building should be strictly greater than the height of the buildings left in order to see the sun.

Example1:
    Input: height = [7, 4, 8, 2, 9]
    Output: 3
    Explanation: 
        As 7 is the first element, it can see the sunrise. 
        4 can't see the sunrise as 7 is hiding it. 
        8 can see. 
        2 can't see the sunrise. 
        9 also can see the sunrise.

Example2:
    Input: height = [2, 3, 4, 5]
    Output: 4
    Explanation: 
        As 2 is the first element, it can see the sunrise.  
        3 can see the sunrise as 2 is not hiding it. 
        Same for 4 and 5, they also can see the sunrise.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 ≤ height.size() ≤ 10^6
    1 ≤ heighti ≤ 10^8
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countBuildings(vector<int> &heights) {
        int mx = -1, count = 0;
        for(int h: heights) 
            if(h > mx) {
                mx = h;
                count++;
            }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}