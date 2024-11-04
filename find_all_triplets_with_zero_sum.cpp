// Find All Triplets with Zero Sum

/*
Given an array arr[], find all possible indices [i, j, k] of triplets [arr[i], arr[j], arr[k]] in the array whose sum is equal to zero. 
Return indices of triplets in any order and all the returned triplets indices should also be internally sorted, 
i.e., for any triplet indices [i, j, k], the condition i < j < k should hold.

Example1:
    Input: arr[] = [0, -1, 2, -3, 1]
    Output: [[0, 1, 4], [2, 3, 4]]
    Explanation: Triplets with sum 0 are:
    arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
    arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0

Example2:
    Input: arr[] = [1, -2, 1, 0, 5]
    Output: [[0, 1, 2]]
    Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0

Example3:
    Input: arr[] = [2, 3, 1, 0, 5]
    Output: [[]]
    Explanation: There is no triplet with sum 0.

Constraints:
    3 <= arr.size() <= 10^3
    -10^4 <= arr[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int , vector<int>> mp ;
        for(int i = 0 ; i < n ; i ++) 
            mp[arr[i]].push_back(i) ;
        
        vector<vector<int>> ans;
        for(int i = 0 ; i < n - 2; ++i){
            for(int j = i + 1 ; j < n - 1; ++j){
                int sumReq = -1*(arr[i] + arr[j]);
                for(int k : mp[sumReq]) {
                    if(k > j)ans.push_back({i , j, k}) ;
                }
            }
        }
        return ans ;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
