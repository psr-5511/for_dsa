#include<iostream>
#include<unordered_set>

using namespace std;


bool subArrayExists(int arr[],int n ) {
    unordered_set<int> sumSet;

    int sum = 0;

    for(int i = 0; i <n; i++)
    {
        sum+=arr[i];


        if(sum==0 || sumSet.find(sum)!=sumSet.end())
            return true;
        
        sumSet.insert(sum);
    }

    return false;
}

int main()
{
    int arr[] = { -3, 2, 3, 1, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    
    return 0;
}

// Time Complexity of this solution can be considered as O(n) under the assumption that we have good hashing function that allows insertion and retrieval operations in O(1) time. 
// Space Complexity: O(n) .Here we required extra space for unordered_set to insert array elements.
