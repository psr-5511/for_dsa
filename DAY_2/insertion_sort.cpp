#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i-1;
        for (; j >=0; j--)
        {
            if(a[j]>temp)
                a[j+1]=a[j];

            else 
                break;
        }

        a[j+1]=temp;
        
    }
    
}

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
} 

int main() 
{

    int arr[] = { 12, 11, 13, 5, 6 }; 
    int N = sizeof(arr) / sizeof(arr[0]); 

    insertion_sort(arr, N);

    printArray(arr,N);
    return 0;
}

// time complexity -> O(n^2)

// space complexity - O(1)