//
// Created by honey on 15-10-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void delete_mid_util(stack<char> &s , int size , int current)
{
    if(current == size / 2)
    {
        s.pop();
        return ;
    }


    int x = s.top();
    s.pop();
    current += 1;

    delete_mid_util(s , size , current);

    s.push(x);
}

void delete_mid(stack<char> &s , int size)
{
    delete_mid_util(s , size , 0);
}

int main()
{
    stack<char> s ;

    s.push('1');
    s.push('2');
    s.push('3');
    s.push('4');
    s.push('5');
    s.push('6');
    s.push('7');

    delete_mid(s , s.size());

    while(!s.empty())
    {
        char x = s.top();
        s.pop();
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}

/* time complexity : O(N)
 * reason : for the recursion calls
 *
 * space complexity : O(N)
 * reason : for the recursion call stack
 * */

