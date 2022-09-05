//
// Created by honey on 04-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int f(vector<int> &arr,int n )
{
    vector<int> ahead(n+1,0), cur(n+1,0);
   ahead[0] = ahead[1] = 0;
    int profit = 0;
    for(int ind = n -1 ; ind>=0; ind--)
    {
        for(int buy = 0 ; buy<=1 ; buy++)
        {


            if(buy){
                profit = max(-arr[ind] + ahead[0] ,
                             0 +ahead[1]);
            }
            else{
                profit = max(arr[ind] + ahead[1] ,
                             0 + ahead[0]);
            }

            cur[buy]=profit;
        }
        ahead = cur;
    }
    return ahead[1];
}
int main()
{
    int n = 6;
    vector<int> arr = {7,1,5,3,6,4};
    int result = f(arr,n);
    cout<<"The maximum value of profit :"<<result;
    return 0;

}
/*
 * time complexity : O(n*2)
 * reason : there are N*2 states therefore at max N*2 new problems will be solved
 * space complexity : O(1)
 * reason : we are using an external array of size 2 .
 * */

