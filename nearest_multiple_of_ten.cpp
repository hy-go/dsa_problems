// Nearest Multiple of 10

/*
    A string str is given to represent a positive number. 
    The task is to round str to the nearest multiple of 10.  
    If you have two multiples equally apart from str, choose the smallest element among them.
    
    Example1:
        Input: str = 29 
        Output: 30

    Example2:
        Input: str = 15
        Output: 10
    
    Expected Time Complexity: O(n).
    Expected Auxiliary Space: O(1).
    
    Constraints:
        1 <= str.size()<= 10^5
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    string roundToNearest(string str) {
        int i = str.length() - 1, c = 0;
        c = str[i] <= '5' ? 0 : 1;
        str[i] = '0';
        i--;
        while(i >= 0 && c) {
            if(str[i] == '9') {
                str[i] = '0';
            } else {
                str[i] = str[i] + 1;
                c = 0;
            }
            i--;
        }
        return (c ? "1" : "") + str;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
