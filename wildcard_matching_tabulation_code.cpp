//
// Created by honey on 02-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool f(string &s1 , string &s2)
{
    int n  = s1.size() , m = s2.size();
    vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , 0));

    dp[0][0] = true;
    for(int j =1 ; j<=m;j++)
        dp[0][j] = false;

    for(int i = 1 ; i<=n ; i++)
    {
        bool flag = true;
        for(int ii=1;ii<=i;i++) {
            if (s1[ii - 1] != '*') {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }


    for(int i = 1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if(s1[i-1] == s2[j-1])  dp[i][j] = dp[i-1][j-1] ;
            else if(s1[i-1] == '*')
                dp[i][j] = dp[i][j-1]|| dp[i-1][j];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}
int main()
{
    string s1 = "ab*cd";
    string s2 = "abdefcd";
    bool result = f(s1,s2);
    cout<<result;

    return 0;

}

