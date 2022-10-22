//
// Created by honey on 15-10-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

bool isBalanced(string &x)
{
    stack<char> s;

    for(int i = 0 ; i < x.length() ; i++)
    {
        if(s.empty())
        {
            s.push(x[i]);
        }
        else if(s.top() == '(' && x[i] == ')' ||
                s.top() == '{' && x[i] == '}' ||
                s.top() == '[' && x[i] == ']')
        {
            s.pop();
        }

        else
        {
            s.push(x[i]);
        }
    }

    if(s.empty())
        return true;
    return false;
}
int main()
{
    string s = "{()}[]";
    if(isBalanced(s))
        cout<<"BALANCED"<<endl;
    else
        cout<<"NOT-BALANCED"<<endl;
    return 0;
}

/* time complexity : O(N)
 * reason : iteration over the string of size N one time
 *
 * space complexity : O(N)
 * reason : O(N) for stack
 * */

