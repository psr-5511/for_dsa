//
// Created by honey on 20-09-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int f(vector<int> &cuts, int n , int c)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    for (int i = c; i >= 1 ; i--) {
        for (int j = 1; j <=c ; j++) {
            if(i>j) continue;
            int mini = INT_MAX; int cost = 0;
            for (int ind = i; ind <=j; ++ind) {
                cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini,cost);
            }

             dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
int main()
{
    vector<int> cuts = {1,3};
    int n = 4 ;
    int c = 2;
    int result = f(cuts,n,c);
    cout<<"The minimum cost to cut the chocolate -->"<<result<<endl;


    return 0;
}