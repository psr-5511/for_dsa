//
// Created by honey on 02-09-2022.
//


#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool  f(int i , int j , string &s1 , string &s2 ,vector<vector<int>> &dp )
{
    if(i==0 && j==0) return true;
    if(i==0 && j>0) return false;

    if(j==0 && i>0) {
        for(int ii=1;ii<=i;i++)
            if(s1[ii] != '*') return false;
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i-1] == s2[j-1] || s1[i-1] == '?') return dp[i][j] = f(i-1,j-1,s1,s2,dp);

    else
    {
        if(s1[i-1] == '*')
            return dp[i][j] =f(i,j-1,s1,s2,dp) || f(i-1,j,s1,s2,dp);
        else
            return dp[i][j] = false;
    }

}
bool wildMatch(string &s1 , string &s2)
{
    int n = s1.size(); int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n,m,s1,s2,dp);
}
int main()
{
    string s1 = "ab*cd";
    string s2 = "abdefcd";
    bool result = wildMatch(s1,s2);
    cout<<result ;

    return 0;

}
