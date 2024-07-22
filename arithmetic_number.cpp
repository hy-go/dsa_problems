// Arithmetic Number

/*
Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' denoting the common difference of an arithmetic sequence and an integer 'B'. 
You need to tell whether 'B' exists in the arithmetic sequence or not. 
Return 1 if B is present in the sequence. Otherwise, returns 0.

Example1:
    Input: 
        A = 1, B = 3, C = 2
    Output: 
        1

Example2:
    Input: 
        A = 1, B = 2, C = 3
    Output: 
        0

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
    -10^9 ≤ A, B, C ≤ 10^9  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int inSequence(int A, int B, int C){
        if(A == B)
            return 1;
        if(B > A) 
            return C > 0 ? (B - A) % C == 0 : 0; 
        return C < 0 ? (A - B) % C == 0 : 0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends