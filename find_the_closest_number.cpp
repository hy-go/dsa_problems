// Find the closest number

/*
Given a sorted array arr[] of positive integers. 
The task is to find the closest value in the array to the given number k. 
The array may contain duplicate values.
Note: If the difference with k is the same for two values in the array return the greater value.

Example 1:
    Input: 
        n = 4
        k = 4
        arr[] = {1, 3, 6, 7}
    Output: 
        3
    Explanation:
        We have array arr={1, 3, 6, 7} and target is 4. 
        If we look at the absolute difference of target with every element of the array we will get { |1-4|, |3-4|, |6-4|, |7-4| }  = {3, 1, 2, 3}. 
        So, the closest number is 3.

Example 2:
    Input:
        n = 7
        k = 4
        arr[] = {1, 2, 3, 5, 6, 8, 9}
    Output:
        5
    Explanation:
        The absolute difference of 4 is 1 from both 3 and 5. 
        According to the question, we have to return greater value, which is 5.

Expected Time Complexity: O(log(n)).
Expected Auxiliary Space: O(1).

Constraints:
    1 ≤ n ≤ 106
    1 ≤ k ≤ 109
    1 ≤ arr[i] ≤ 109
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) {
        int lb = lower_bound(arr, arr+n, k) - arr;
        if(lb == 0)
            return arr[0];
        if(lb == n)
            return arr[n-1];
        return arr[lb] - k <= k - arr[lb - 1] ? arr[lb] : arr[lb - 1]; 
    } 
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}