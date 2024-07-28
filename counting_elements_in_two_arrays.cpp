// Counting elements in two arrays

/*
Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. 
For each element in arr1[] count elements less than or equal to it in array arr2[].

Example 1:
    Input:
        m = 6, n = 6
        arr1[] = {1,2,3,4,7,9}
        arr2[] = {0,1,2,1,1,4}
    Output: 
        4 5 5 6 6 6
    Explanation: 
        Number of elements less than or equal to 1, 2, 3, 4, 7, and 9 in the second array are respectively 4,5,5,6,6,6

Example 2:
    Input:
        m = 5, n = 7
        arr1[] = {4,8,7,5,1}
        arr2[] = {4,48,3,0,1,1,5}
    Output: 
        5 6 6 6 3
    Explanation: 
        Number of elements less than or equal to 4, 8, 7, 5, and 1 in the second array are respectively 5,6,6,6,3

Expected Time Complexity: O(M logN + N logN).
Expected Auxiliary Space: O(m).

Constraints:
    1<=m,n<=10^5
    0<=arr1[i],arr2[j]<=10^5
*/

#include <bits/stdc++.h>
 
using namespace std;

class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n) {
        sort(arr2, arr2+n);
        vector<int> res(m);
        for(int i = 0; i < m; ++i) {
            int ub = upper_bound(arr2, arr2+n, arr1[i]) - arr2;
            res[i] = ub;
        }
        return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}