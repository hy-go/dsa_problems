// Remove Duplicates in Array

/*
Given an array arr consisting of positive integers numbers, remove all duplicates numbers.

Example1:
    Input: arr[] = [2, 2, 3, 3, 7, 5] 
    Output: [2, 3, 7, 5]

Example2:
    Input: arr[] = [2, 2, 5, 5, 7, 7] 
    Output: [2, 5, 7]

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
    1 <= arr.size() <= 10^6
    2 <= arr[i] <= 100
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // if number in the array are small primes
    /*
        vector<int> removeDuplicate(vector<int>& arr) {
            vector<int> res;
            int p = 1;
            for(int a: arr)
                if(p % a != 0) {
                    p *= a;
                    res.push_back(a);
                }
            return res;
        }
    */
    
    // long version of solution
    /*
        vector<int> removeDuplicate(vector<int>& arr) {
            map<int, int> mp;
            vector<int> res;
            for(int a: arr)
                if(mp.find(a) == mp.end()) {
                    mp[a] = 1;
                    res.push_back(a);
                }
            return res;
        }
    */
    
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        arr.assign(s.begin(), s.end());
        reverse(arr.begin(), arr.end());
        return arr;
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
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
