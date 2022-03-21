#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void sortArr(int arr[],int n)
{
    int i , cnt0=0,cnt1=0, cnt2=0;
    // count the number of 0s 1s and 2s in the array

    for(int i=0; i<n; i++)
    {
        switch(arr[i])
        {
            case 0:
            cnt0++;
            break;

            case 1:
            cnt1++;
            break;

            case 2:
            cnt2++;
            break;

        }
    }

    // update the array

    i=0;

    // stores all the zeroes in the beginning 
    while(cnt0>0)
    {
        arr[i++]=0;
        cnt0--;

    }
    // stores all the 1s in the beginning
     while(cnt1>0)
    {
        arr[i++]=1;
        cnt1--;

    }
    // stores all the 2s in the beginning
     while(cnt2>0)
    {
        arr[i++]=2;
        cnt2--;

    }

    printArr(arr, n);

}
int main()
{
     int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(int);
 
    sortArr(arr, n);
 
    return 0;
}


// Time Complexity: O(n). 
//Space Complexity: O(1). 