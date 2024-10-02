// Majority Vote

/*
You are given an array of integer nums[] where each number represents a vote to a candidate. 
Return the candidates that have votes greater than one-third of the total votes, 
If there's not a majority vote, return -1. 

Example1:
    Input: nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
    Output: [5, 6]
    Explanation: 5 and 6 occur more n/3 times.

Example2:
    Input: nums = [1, 2, 3, 4, 5]
    Output: [-1]
    Explanation: no candidate occur more than n/3 times.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraint:
    1 <=  nums.size()  <= 10^6
    -10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        // Using Boyer-Moore Majority Voting Algorithm
        int n = nums.size(), a = -1, aCount = 0, b = -1, bCount = 0;
        for(int i: nums) {
            if(a == i) 
                aCount++;
            else if(b == i)
                bCount++;
            else {
                if(aCount == 0) {
                    aCount = 1;
                    a = i;
                }
                else if(bCount == 0) {
                    bCount = 1;
                    b = i;
                } else {
                    aCount--;
                    bCount--;
                }
            }
        }
        aCount = 0;
        bCount = 0;
        int last;
        for(int i: nums) {
            if(i == a)
                aCount++;
            if(i == b) 
                bCount++;
        }
        vector<int> res;
        if(aCount > n/3)
            res.push_back(a);
        if(bCount > n/3)
            res.push_back(b);
        if(res.empty())
            res.push_back(-1);
        return res; 
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

