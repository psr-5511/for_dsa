//
// Created by honey on 15-10-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void insert_at_bottom(stack<int> &s , int x)
{
    if(s.size() == 0)
    {
        s.push(x);
    }
    else
    {
        int a = s.top();
        s.pop();
        insert_at_bottom(s,x);
        s.push(a);
    }
}

void reverse(stack<int> &s)
{
    if(s.size() > 0)
    {
        int a = s.top();
        s.pop();
        reverse(s);
        insert_at_bottom(s,a);
    }
    return ;
}
int main()
{
    stack<int> st1 , st2 ;
    for (int i = 1; i <= 4; ++i) {
        st1.push(i);
    }

     st2 = st1 ;
    cout<< "Original Stack is :"<<" ";
    while(!st1.empty())
    {
        int ans = st1.top();
        st1.pop();
        cout<< ans << " ";
    }
    cout<<endl;

    reverse(st2);
    cout << "Reversed stack is :" << " ";

    while(!st2.empty())
    {
        int ans = st2.top();
        st2.pop();
        cout<< ans << " ";
    }
    cout<<endl;

    return 0;
}

/* time complexity : O(N*N)
 * reason : recursion calls for two functions are going on
 *
 * space complexity : O(N)
 * reason : use of recursion stack space and use of stack space
 * */

