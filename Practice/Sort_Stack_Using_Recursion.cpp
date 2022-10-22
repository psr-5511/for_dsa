//
// Created by honey on 15-10-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void sortedInsert(stack<int> &s , int x)
{
    if(s.empty() || x > s.top())
    {
        s.push(x);
        return ;
    }

    int temp = s.top();
    s.pop();
    sortedInsert(s , x);
    s.push(temp);
}

void sortedStack(stack<int> &s)
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();
        sortedStack(s);
        sortedInsert(s,x);
    }
}
int main()
{
    stack<int> s1 , s2 ;
    s1.push(30);
    s1.push(-5);
    s1.push(18);
    s1.push(14);
    s1.push(-3);

    s2 = s1;

    cout<< "Stack elements before sorting : " ;
    while(!s2.empty())
    {
        int x = s2.top();
        s2.pop();
        cout << x << " ";
    }

    sortedStack(s1);

    cout<<endl;
    cout<< "Stack elements after sorting : ";

    while(!s1.empty())
    {
        int x = s1.top();
        s1.pop();
        cout << x << " ";
    }
    return 0;
}
/* time complexity : O(N*N)
 * reason : two recursive calls are going on
 *
 * space complexity : O(N)
 * reason : for stack and for recursion stack space
 * */

