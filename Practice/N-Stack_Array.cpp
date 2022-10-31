//
// Created by honey on 27-10-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class NStack{
    int *arr ;
    int *top ;
    int *next;
    int n , s;
    int freespot;

public:
    // Initialize your data structure
     NStack(int N , int S)
    {
        n = N ;
        s = S ;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialize
        for(int i = 0 ; i < n ; i++)
            top[i] = -1;
        // next initialize

        for(int i = 0 ; i < s; i++)
            next[i] = i +1 ;

        // update last index value to -1 ;
        next[s-1] = -1;

        // initialize free spot
        freespot = 0 ;
    }
    // Pushes X into the Mth Stack . Returns true if it gets pushed into the stack
    bool push(int x , int m)
    {
        // check for overflow
        if(freespot == -1)
            return false;
        // find index
        int index = freespot;

        // insert element into the array
        arr[index] = x;

        // update free spot
        freespot = next[index] ;

        //update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from the Mth stack . Returns -1 if the stack is empty , otherwise returns the popped element
    int pop(int m)
    {
        // check for underflow condition
        if(top[m-1] == -1)
            return false;
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot ;

        freespot = index ;

        return arr[index] ;
    }

};
int main()
{
    NStack obj(3,10);

    obj.push(15,2);
    obj.push(45,2);
    obj.push(17,1);
    obj.push(49,1);
    obj.push(39,1);

    cout<<obj.pop(2) << endl ;

    cout << obj.pop(1) << endl;
    return 0;
}

/* time complexity : O(1)
 *
 * space complexity : O(n + s)
 *
 * */

