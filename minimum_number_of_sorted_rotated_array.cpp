// Minimum Number in a sorted rotated array

/*
Given an array of distinct elements which was initially sorted. 
This array may be rotated at some unknown point. 
The task is to find the minimum element in the given sorted and rotated array. 

Example1:
    Input:
        N = 10
        arr[] = {2,3,4,5,6,7,8,9,10,1}
    Output: 
        1
    Explanation: 
        The array is rotated once anti-clockwise. 
        So minimum element is at last index (n-1) which is 1.

Example2:
    Input:
        N = 5
        arr[] = {3,4,5,1,2}
    Output: 
        1
    Explanation: 
        The array is rotated and the minimum element present is at index (n-2) which is 1.

Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(LogN).

Constraints:
    1 <= N <= 10^7
    1 <= arr[i] <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minNumber(int arr[], int low, int high) {
        int s = low, e = high, m, mi = INT_MAX;
        while(s <= e) {
            m = (s + e) / 2;
            if(arr[s] <= arr[m]) {
                // left side is sorted
                mi = min(mi, arr[s]);
                s = m+1;
            }
            else {
                // right side is sorted
                mi = min(mi, arr[m]);
                e = m-1;
            }
        }
        return mi;
    }
};

int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}