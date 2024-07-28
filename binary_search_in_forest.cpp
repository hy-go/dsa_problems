// Binary Search in forest

/*
There are n trees in a forest. 
The heights of the trees is stored in array tree[], where tree[i] denotes the height of the ith tree in the forest. 
If the ith tree is cut at a height H, then the wood collected is tree[i] - H, provided tree[i] > H. 
If the total woods that needs to be collected is exactly equal to k, find the height H at which every tree should be cut (all trees have to be cut at the same height). 
If it is not possible then return -1 else return H.

Example1:
    Input:
        n = 5, k = 4
        tree[] = {2, 3, 6, 2, 4}
    Output: 
        3
    Explanation: 
        Wood collected by cutting trees at height 3 = 0 + 0 + (6-3) + 0 + (4-3) = 4
        hence 3 is to be subtracted from all numbers.
        Since 2 is lesser than 3, nothing gets subtracted from it.

Example2:
    Input:
        n = 6, k = 8
        tree[] = {1, 7, 6, 3, 4, 7}
    Output: 
        4
    Explanation: 
        Wood collected by cutting trees at height 4 = 0+(7-4)+(6-4)+0+0+(7-4) = 8.

Expected Time Complexity: O(n log h)
Expected Auxiliary Space: O(1)

Constraints: 
    1 <= n <= 10^4
    1 <= tree[i] <= 10^3
    1 <= k <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int find_height(int tree[], int n, int k) {
        int s = 1, e = *max_element(tree, tree + n), m;
        while(s <= e) {
            m = (s + e) / 2;
            int woodCollected = 0;
            for(int i = 0; i < n; ++i)
                if(tree[i] >= m)
                    woodCollected += tree[i] - m;
            if(woodCollected == k)
                return m;
            if(woodCollected < k)
                e = m - 1;
            else
                s = m + 1;
        }
        return -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}