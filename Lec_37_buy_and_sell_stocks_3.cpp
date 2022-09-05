//
// Created by honey on 05-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int> &arr, int ind , int buy , int c,int n , vector<vector<vector<int>>> &dp)
{
    if(ind==n || c==0)
        return 0;
    if(dp[ind][buy][c]!=-1) return dp[ind][buy][c];
    int profit = 0;

    if(buy)
    {
        profit = max(-arr[ind] + f(arr,ind+1,0,c,n,dp) ,
                     0+ f(arr,ind+1 , 1,c,n,dp));
    }
    else
    {
        profit = max(arr[ind] + f(arr,ind+1,1,c-1,n,dp),
                0 + f(arr,ind+1,0,c,n,dp));
    }
    return dp[ind][buy][c] = profit ;

}
int buy_and_sell(vector<int> &arr, int n)
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(arr,0,1,2,n,dp);
}
int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();
    int result = buy_and_sell(prices , n);
    cout<<"The maximum profit that can be generated :"<<result ;
    return 0;

}
/*
  Time Complexity: O(N*2*3)

Reason: There are N*2*3 states therefore at max ‘N*2*3’ new problems will be solved.

Space Complexity: O(N*2*3) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 3D array ( O(N*2*3)).

 */

