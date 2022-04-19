#include<iostream>
using namespace std;


// Function to shift all the negative elements on left side

void shiftall(int arr[],int left, int right)
{
    // Loop to iterate over the array from left to right

    while (left <=right)
    {
        // Condition to check if left and right elements are negative

        if(arr[left]<0 && arr[right]<0)
        {
            left+=1;
        }

        // Condition to check if left pointer element is positive and the right pointer element is negative

        else if(arr[left]>0 && arr[right<0])
        {
            swap(arr[left],arr[right]);
            left+=1;
            right-=1;
        }

        else if(arr[left]>0 && arr[right]>0)
        {
            right-=1;
        }
        else{
            left+=1;
            right-=1;
        }
    }
}

void display(int arr[], int right){
   
  // Loop to iterate over the element
  // of the given array
  for (int i=0;i<=right;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main()
{
    int arr[] = {-12, 11, -13, -5,
               6, -7, 5, -3, 11};
  int arr_size = sizeof(arr) /
                sizeof(arr[0]);
   
  // Function Call
  shiftall(arr,0,arr_size-1);
  display(arr,arr_size-1);
    return 0;
}