//
// Created by honey on 11-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int> lds(vector<int> & arr , int n )
{
    sort(arr.begin(),arr.end());

    vector<int> dp(n,1);
    vector<int> hash(n,1);

    for (int i = 0; i < n; ++i) {
        hash[i] = i;
        for (int prev = 0; prev <=i - 1; ++prev) {
            if(arr[i] % arr[prev] == 0 && 1+dp[prev] > dp[i]){
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
        }
    }

    int ans = -1 ;
    int last_index = -1 ;
    for (int i = 0; i < n; ++i) {
        if(dp[i] > ans) {
            ans = dp[i];
            last_index = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[last_index]);

    while(hash[last_index] != last_index){
        last_index = hash[last_index];
        temp.push_back(arr[last_index]);
    }

    reverse(temp.begin(),temp.end());
    return temp ;

}
int main()
{
    vector<int> arr = {1,16,7,8,4};
    int n = arr.size();
    vector<int> ans = lds(arr,n);

    cout<<"The longest divisible subset elements are :";
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" " ;
    }
    return 0;
}

/* time complexity : O(N*N)
 * reason : there are two nested loops
 *
 * space complexity : O(N)
 * reason : we are only using two rows of size N .
 * */
