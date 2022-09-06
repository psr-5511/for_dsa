//
// Created by honey on 06-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int> &arr, int n , int k )
{
    vector<vector<int>> dp(n+1,vector<int>(2*k +1,0));
    for(int ind = n -1 ; ind>=0 ; ind--)
    {
        for(int tranNo = 2*k -1 ; tranNo>=0 ; tranNo--){
            if(tranNo % 2 == 0)
            {
                dp[ind][tranNo] = max(-arr[ind] + dp[ind+1][tranNo +1]
                        , 0 + dp[ind+1][tranNo]);
            }
            else
                dp[ind][tranNo] =  max(arr[ind] + dp[ind+1][tranNo +1]  ,
                           0 + dp[ind+1][tranNo]);
        }
    }
    return dp[0][0];
}
int main()
{
    vector<int> arr = {3,3,5,0,0,3,1,4};

    int n = arr.size();
    int k =2 ;
    int result = f(arr,n,k);
    cout<<"The maximum value of profit will be :"<<result;
    return 0;

}

