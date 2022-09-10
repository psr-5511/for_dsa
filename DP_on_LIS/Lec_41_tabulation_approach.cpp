//
// Created by honey on 10-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int get_ans(int n , vector<int> &arr)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind = n-1 ; ind>=0 ; ind-- )
    {
        for(int prev_ind = ind-1 ; prev_ind>=-1 ; prev_ind--)
        {
            int not_take = -1e9;

            not_take = 0 + dp[ind+1][prev_ind+1];
            int take = -1e9;
            if(prev_ind == -1 || arr[ind] > arr[prev_ind])
                take =  1+ dp[ind+1][ind+1];

             dp[ind][prev_ind+1]=max(take , not_take);
        }
    }
    return dp[0][-1+1];
}
int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();

    int result = get_ans(n,arr);
    cout<<"The length of the longest increasing subsequence is :"<<result;
    return 0;

}

/*
 * time complexity : O(N*N)
 * reason :there are N*N states therefore at max N*N new problems will be solved
 *
 * space complexity : O(N*N)
 * reason : a 2-D array of size O(N*(N+1))
 * */

