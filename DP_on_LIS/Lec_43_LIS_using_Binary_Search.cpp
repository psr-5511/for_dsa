//
// Created by honey on 11-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int LIS_using_BS(vector<int> &arr, int n )
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len =1 ;
    for (int i = 1; i < n; ++i) {
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len ;
}
int main()
{
    vector<int> arr =  {10,9,2,5,3,7,101,18};
    int n = arr.size();
    cout<<"The length of the longest increasing subsequence :"<<LIS_using_BS(arr,n);
    return 0;
}
/* time complexity : O(N*logN)
 * reason : we iterate over the array of size N and in  every iteration , we perform a binary search
 *          which takes logN time .
 *
 *  space complexity: O(N)
 *  reason : we are using an extra array of size  N  to store the temp variable .
 * */

