//
// Created by honey on 10-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int getAns(int ind , int prev_ind , vector<int> &arr,int n,vector<vector<int>> &dp )
{
    if(ind==n)
        return 0;
    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    int not_take = -1e9;

     not_take = 0 + getAns(ind+1 , prev_ind , arr , n,dp);
    int take = -1e9;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind])
         take =  1+ getAns(ind+1 , ind , arr, n,dp);

    return dp[ind][prev_ind+1]=max(take , not_take);

}
int lis(vector<int> &arr , int n )
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return getAns(0,-1,arr,n,dp);
}
int main()
{
   vector<int> arr = {10,9,2,5,3,7,101,18};
  // vector<int> arr = {4,2,6};
    int n = arr.size();

    int result = lis(arr,n);
    cout<<"The length of the longest increasing subsequence is :"<<result;

    return 0;

}
/*
 * time complexity : O(N*N)
 * reason :there are N*N states therefore at max N*N new problems will be solved
 *
 * space complexity : O(N*N) + O(N)
 * reason : auxiliary stack space of O(N) (see the recursive tree , in the worst case we will go till N calls at a time )
 *          and a 2-D array of size O(N*(N+1))
 * */

