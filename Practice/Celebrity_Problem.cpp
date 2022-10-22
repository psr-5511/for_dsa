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
                     {0, 0, 1, 0}
};

bool knows(int a, int b) {
    return MATRIX[a][b];
}

// Returns -1 if a potential celebrity is not present .
// If Present returns' id from 0 to n-1 .
int potential_celebrity(int n) {
    // base case : when n reaches 0  , returns -1
    // since n represents the number of people ,
    // 0 people implies no celebrity (= -1)
    if (n == 0)
        return -1;

    // find the celebrity with n-1 persons

    int id = potential_celebrity(n - 1);

    // if there are no celebrities

    if (id == -1)
        return (n-1);

        // if the id knows the nth person then the id can't be a celebrity but the nth person can be the one
    else if (knows(id, n - 1))
        return (n-1);
        // if the nth person knows the id then the nth person  can't be a celebrity but the id can be the one

    else if (knows(n - 1, id))
        return id;

    // if there is no celebrity
    return -1;
}
// Returns -1 if the celebrity is not present . If present returns id (value from 0 to n-1 ),
// a wrapper function over potential_celebrity() .
int Celebrity(int n )
{
    // find the celebrity
    int id = potential_celebrity(n);

    // check if the celebrity found is really the celebrity

    if(id == -1)
        return id;
    else{
        int c1 = 0 , c2 = 0 ;
        for (int i = 0; i < n; ++i) {
            if(i!=id)
            {
                c1 += knows(id , i);
                c2 += knows(i , id);
            }
        }
        if(c1 == 0 && c2 == n-1)
            return id;
        return -1 ;
    }
}

int main() {
    int n = 4 ;
    int id = Celebrity(n);
    id == -1 ? cout << "No celebrity" << endl : cout << "Celebrity id :" << id << endl;
    return 0;
}

// time complexity : O(N)
// reason : the recursive function is called n times .

// space complexity : O(1)
// reason : no extra space is required .

