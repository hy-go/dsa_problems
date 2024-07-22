// Pairs with certain difference
/*
Given an array of integers, arr[] and a number, K.
You can pair two numbers of the array if the difference between them is strictly less than K. 
The task is to find the maximum possible sum of such disjoint pairs (i.e., each element of the array can be used at most once). 
The Sum of P pairs is the sum of all 2P elements of pairs.

Example1:
    Input: 
        arr[] = {3, 5, 10, 15, 17, 12, 9}
        K = 4
    Output: 
        62
    Explanation:
        One of the disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17);
        then, sum which we can get is 3 + 5 + 10 + 12 + 15 + 17 = 62. (which is the maximum)
        Note that an alternate way to form  disjoint pairs is,(3, 5), (9, 12), (15, 17) but this pairing produces less sum.

Example2:
    Input:
        arr[] = {5, 15, 10, 300}
        K = 12
    Output: 
        25

Expected Time Complexity: O(N.log(N))
Expected Auxiliary Space: O(N)

Constraints:
    1 ≤ N ≤ 10^5
    0 ≤ K ≤ 10^5
    1 ≤ arr[i] ≤ 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {
        if(N == 1)
            return 0;
        sort(arr, arr+N);
        int dp[N];
        dp[0] = 0;
        dp[1] = arr[1] - arr[0] < K ? arr[1] + arr[0] : 0;
        for(int i = 2; i < N; ++i) {
            int take = (arr[i] - arr[i-1] < K) ? dp[i - 2] + arr[i] + arr[i-1] : 0;
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[N-1];
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
