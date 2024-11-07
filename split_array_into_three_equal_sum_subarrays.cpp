// Split array in three equal sum subarrays

/*
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. 
If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Driver code will print true if arr can be split into three equal sum subarrays, otherwise, it is false.

Example1:
    Input:  arr[] = [1, 3, 4, 0, 4]
    Output: true
    Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4. 

Example2:
    Input: arr[] = [2, 3, 4]
    Output: false
    Explanation: No three subarrays exist which have equal sum.

Example3:
    Input: arr[] = [0, 1, 1]
    Output: false

Constraints:
    3 ≤ arr.size() ≤ 10^6
    0 ≤ arr[i] ≤ 10^6

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // using 2 pointers
    /*
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3)
            return {-1, -1};
        int l = arr[0], r = arr[n - 1], c = sum - l - r;
        int i = 0, j = n - 1;
        while(i + 1 < j) {
            if(l == c && c == r)
                return {i, j};
            if(l < r) {
                if(c < l)
                    return {-1, -1};
                c -= arr[i + 1];
                l += arr[i + 1];
                i++;
            }
            else if(r < l) {
                if(c < r)
                    return {-1, -1};
                c -= arr[j - 1];
                r += arr[j - 1];
                j--;
            }
            else {
                if(c < l) 
                    return {-1, -1};
                if(c == l)
                    return {i, j};
                c -= arr[i + 1];
                l += arr[i + 1];
                i++;
            }
        }
        return {-1, -1};
    }
    */
    
    // using prefix sum
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3)
            return {-1, -1};
        int target = sum / 3;
        int f = -1, s = -1;
        int i = 0;
        int prefixSum = 0;
        while(i < n) {
            prefixSum += arr[i++];
            if(prefixSum == target) {
                f = i;
                break;
            }
            if(prefixSum > target)
                return {-1, -1};
        }
        while(i < n) {
            prefixSum += arr[i++];
            if(prefixSum == 2*target) {
                s = i;
                break;
            }
            if(prefixSum > 2*target)
                return {-1, -1};
        }
        return {f, s};
    }
};

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}
