//
// Created by honey on 10-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int print_LIS(vector<int> &arr, int n)
{
    vector<int> dp(n,1);
    vector<int> hash(n,1);
    for (int i = 0; i <= n-1; ++i) {
        hash[i] = i;
        for (int prev_ind = 0; prev_ind <= i-1; ++prev_ind) {
            if(arr[prev_ind] < arr[i] && 1+dp[prev_ind] > dp[i]){
                dp[i] = dp[prev_ind] +1 ;
                hash[i] = prev_ind;
            }
        }
    }
    int ans = -1;
    int last_index = -1;

    for (int i = 0; i <=n-1; ++i) {
//        ans = max(ans , dp[i]);
        if(dp[i]>ans) ans= dp[i];
        last_index = i;
    }

    vector<int> temp;
    temp.push_back(arr[last_index]);
    while(hash[last_index] != last_index){
        last_index = hash[last_index];
        temp.push_back(arr[last_index]);
    }

    reverse(temp.begin(),temp.end());

    for (int i = 0; i < temp.size(); ++i) {
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    return ans ;
}
int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();
    int result = print_LIS(arr,n);
    cout<<"The length of lis is :"<<result;
    return 0;

}

/*  time complexity : O(N*N)
 *  reason : there are two nested loops
 *
 *  space complexity : O(N)
 *  we are using two rows of size N .
 * */

