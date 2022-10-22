//
// Created by honey on 15-10-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

stack<int> recur(stack<int> s , int N)
{
    if(s.empty())
    {
        s.push(N);
    }

    else
    {
        int x = s.top();
        s.pop();
        s = recur(s,N);
        s.push(x);
    }
    return s;
}

void insert_at_bottom(stack<int> s , int N)
{
    s = recur(s,N);

    while(!s.empty())
    {
        int x = s.top();
        s.pop();
        cout<< x << " ";
    }
    cout<<endl;
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    insert_at_bottom(s, 7);
    return 0;
}

/* time complexity : O(N)
 * reason : where N is the total no of elements in the stack .
 *
 * space complexity : O(N) + O(N)
 * reason : for stack + for recursion stack
 * */