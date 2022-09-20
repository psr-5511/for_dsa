//
// Created by honey on 20-09-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int> &cuts,  int i , int j, vector<vector<int>> &dp)
{
    if(i>j) return 0 ;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX; int cost = 0;
    for (int ind = i; ind <=j; ++ind) {
        cost = cuts[j+1] - cuts[i-1] + f(cuts,i,ind-1,dp) + f(cuts,ind+1,j,dp);
        mini = min(mini,cost);
    }

    return dp[i][j] = mini;
}
int cost(int n , int c , vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    return f(cuts,1,c,dp);
}
int main()
{
    vector<int> cuts = {1,3};
        int n = 4 ;
        int c = 2;
        int result = cost(n,c,cuts);
        cout<<"The minimum cost to cut the chocolate :"<<result<<endl;

    return 0;
}

/*  time complexity : O(N*N*N)
 *  reason : there are three nested loops , also n is not the length of the rod it is the length of cuts array .
 *
 *  space complexity : O(N*N) + O(N)
 *  reason : for memory matrix + recursion stack space is needed .
 * */

