#include<iostream>
#include<vector>
using namespace std;



int minDis(string str1,string str2,int n,int m , vector<vector<int>> &dp)
{
    //If any string is empty return the remaining character of other string 

    if(n==0) return m;

    if(m==0) return n;

    // to check if the recursive tree for given n and m has already been executed   
    if(dp[n][m]!=-1) return dp[n][m];

    // if characters are equal , then execute recursive function for n-1,m-1

    if(str1[n-1]==str2[m-1])
    {
        if(dp[n-1][m-1]==-1)
        {
            return dp[n][m]= minDis(str1,str2,n-1,m-1,dp);
        }

        else
        {
            return dp[n][m] = dp[n-1][m-1];
        }
    }

    // if characters are not equal we need to find the minimum cost out of all three operations

    else
    {
        int m1,m2,m3;

        if(dp[n-1][m]!=-1)
            m1 = dp[n-1][m];
        else
            m1 = minDis(str1,str2,n-1,m,dp);


        if(dp[n][m-1]!=-1)
            m2 = dp[n][m-1];
        else
            m2 = minDis(str1,str2,n,m-1,dp);


        if(dp[n-1][m-1]!=-1)
            m3 = dp[n-1][m-1];
        else
            m3 = minDis(str1,str2,n-1,m-1,dp);

        
        return dp[n][m] = 1 +min(m1,min(m2,m3));
    }

    
}
int main()
{
    string str1 ="voldemort";
    string str2 ="dumbledore";

    int n =str1.length();
    int m =str2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    cout<<minDis(str1,str2,str1.length(),str2.length(),dp);
    return 0;
}


