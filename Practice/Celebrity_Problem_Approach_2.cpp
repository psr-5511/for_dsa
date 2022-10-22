//
// Created by honey on 22-10-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define N 8

bool MATRIX[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b)
{
    return MATRIX[a][b];
}
// Returns -1 if celebrity is not present . If present returns id value from 0 to n-1 .
int find_celebrity(int n)
{
    stack<int> s;

    // celebrity

    int C;
    // push every element to stack

    for (int i = 0; i < n; ++i) {
        s.push(i);
    }

    // Extract top 2
    // find a potential celebrity

    while(s.size() > 1)
    {
        int A = s.top() ;
        s.pop();
        int B = s.top() ;
        s.pop();
        if(knows(A,B))
            s.push(B);
        else
            s.push(A);
    }

    // potential candidate
    C = s.top() ;
    s.pop();

    // check if C is actually a celebrity or not
    for (int i = 0; i < n; ++i) {
        // if any person doesn't know C or if C knows any person then return -1
        if((i!=C) && (knows(C,i) || !knows(i,C)))
            return -1 ;
    }
    return C;
}

int main()
{
    int n = 4;
    int id = find_celebrity(n);
    id == -1 ? cout << "No celebrity" :
    cout << "Celebrity ID " << id;
    return 0;
}
// time complexity : O(N)
// reason : the total number of comparisons 3*(N-1) .

// space complexity : O(N)
// reason : n extra space is needed to store the stack .

