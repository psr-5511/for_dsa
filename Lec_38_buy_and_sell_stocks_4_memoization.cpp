//
// Created by honey on 06-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int> &arr, int ind ,int tranNo, int k , int n , vector<vector<int>> &dp)
{
    if(ind==n || tranNo == 2*k ) return 0;
    if(tranNo % 2 == 0)
    {
        return max(-arr[ind] + f(arr,ind+1 , tranNo +1 , k , n,dp )
        , 0 + f(arr,ind+1 , tranNo , k ,n,dp ));
    }
    else
        return max(arr[ind] + f(arr,ind+1 , tranNo +1 , k , n,dp) ,
                   0 + f(arr,ind+1 , tranNo , k , n ,dp));
}
int buy_and_sell(vector<int> &arr, int n , int k )
{
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
    return f(arr, 0, 0,k,n,dp);
}
int main()
{
    vector<int> arr = {3,3,5,0,0,3,1,4};

    int n = arr.size();
    int k =2 ;
    int result = buy_and_sell(arr,n,k);
    cout<<"The maximum value of profit will be :"<<result;
    return 0;

}

