//
// Created by honey on 04-09-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int> &arr,int ind ,int n , int buy,vector<vector<int>> &dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    int profit = 0;

    if(buy){
        profit = max(-arr[ind] + f(arr,ind+1,n,0,dp) ,
                0 + f(arr,ind+1,n,1,dp));
    }
    else{
        profit = max(arr[ind] + f(arr,ind+1 , n, 1,dp) ,
                0 + f(arr,ind+1 , n , 0,dp));
    }

    return dp[ind][buy]=profit;
}
int buy_and_sell(vector<int> &arr,int n )
{
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(arr, 0,n,1,dp);
}
int main()
{
    int n = 6;
    vector<int> arr = {7,1,5,3,6,4};
    int result = buy_and_sell(arr,n);
    cout<<"The maximum profit that can be generated is :"<<result ;

    return 0;

}

/*
 * time complexity : O(n*2)
 * reason : there are N*2 states therefore at max N*2 new problems will be solved
 * space complexity : O(N*2) + O(N)
 * reason : 2-d array + recursion stack space
 * */

