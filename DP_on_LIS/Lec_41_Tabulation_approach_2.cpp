//
// Created by honey on 10-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int> &arr,int n )
{
    vector<int> dp(n+1 , 1);
    for (int i = 0; i <= n - 1; ++i) {
        for (int prev_ind = 0; prev_ind <=i-1; ++prev_ind) {
                if(arr[prev_ind] < arr[i]){
                    dp[i] = max(dp[i] , 1+ dp[prev_ind]);
                }
        }
    }
    int ans = -1 ;
    for (int i = 0; i <=n-1 ; ++i) {
        ans = max(ans , dp[i]);
    }
    return ans ;
}
int main()
{
    vector<int> arr  = {10,9,2,5,3,7,101,18};
    int n = arr.size();
    cout<<"The length of the longest increasing subsequence is :"<<f(arr,n);

    return 0;

}

/* time complexity :O(N*N)
 * reason : there are N*N states therefore at max N*N new problems will be solved .
 *
 * space complexity : O(N)
 * reason : we are only using two rows of size N . 
 * */


