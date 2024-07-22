// Maximum Sum Subarray of size K

/*
Given an array of integers Arr of size N and a number K. 
Return the maximum sum of a subarray of size K.
Note: A subarray is a contiguous part of any given array.

Example1:
    Input: 
        N = 4
        K = 2
        Arr = [100, 200, 300, 400]
    Output: 
        700

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
    1 <= N <= 10^5
    1 <= Arri <= 10^5
    1 <= K <= N
*/

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N) {
        long sum = 0;
        for(int i = 0; i < K; ++i)
            sum += Arr[i];
        long maxSum = sum;
        for(int i = K; i < N; ++i) {
            sum += Arr[i] - Arr[i-K];
            if(sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 