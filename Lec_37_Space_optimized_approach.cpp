//
// Created by honey on 05-09-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int>&arr , int n )
{
   vector<vector<int>> ahead(2,vector<int>(3,0));
   vector<vector<int>> cur(2,vector<int>(3,0));
    int profit = 0;
    for(int ind = n-1 ; ind>=0 ; ind--)
    {
        for(int buy = 0 ; buy<=1; buy++)
        {
            for(int c =1 ; c<=2 ; c++)
            {
                if(buy)
                {
                    profit = max(-arr[ind] + ahead[0][c] ,
                                 0+ ahead[1][c]);
                }
                else
                {
                    profit = max(arr[ind] + ahead[1][c-1],
                                 0 + ahead[0][c]);
                }
                cur[buy][c] = profit ;
            }
        }
        ahead = cur;
    }
    return ahead[1][2];
}
int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();

    int result = f(prices , n);
    cout<<"The maximum that can be generated ---"<<result ;


    return 0;

}
/*
  Time Complexity: O(N*2*3)

    Reason: There are three nested loops that account for O(N*2*3) complexity

    Space Complexity: O(1)

    Reason: We are using two external arrays of size ‘2*3’.
*/


