#include<iostream>

using namespace std;

// Function to sort the input array ,
// the array is assumed to have values in {0,1,2};

void sort012(int a[], int arr_size)
{
    int lo=0;
    int hi=arr_size-1;
    int mid=0;

    // Iterate till all the elements are same 

    while(mid<=hi) {
        switch (a[mid])
        {
            // if the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;
            // if the element is 1
        case 1:
            mid++;
            break;
        
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}

// function to print the array 

void printArray(int arr[],int arr_size)
{
    for(int i=0;i<arr_size;i++)
        cout<< arr[i] << " ";
}


int main()
{
     int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
      int n = sizeof(arr) / sizeof(arr[0]);

      sort012(arr, n);

      
      cout << "array after segregation ";
 
    printArray(arr, n);
    
    return 0;
}


// time complexity -> O(n)
// space complexity -> O(1)