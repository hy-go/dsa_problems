// Parenthesis Checker

/*
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
Note: The driver code prints "balanced" if function return true, otherwise it prints "not balanced".

Example1:
    Input: {([])}
    Output: true
    Explanation: 
        { ( [ ] ) }. 
        Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.

Example2:
    Input: ([]
    Output: false
    Explanation: 
        ([]. Here square bracket is balanced but the small bracket is not balanced. 
        Hence , the output will be unbalanced.

Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
    1 ≤ |x| ≤ 10^5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x) {
        stack<char> stk;
        for(char c: x) {
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if(stk.empty() || (c == ')' && stk.top() != '(') || (c == '}' && stk.top() != '{') || (c == ']' && stk.top() != '['))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}