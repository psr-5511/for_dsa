//
// Created by honey on 02-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool f(string &s1 , string &s2)
{
    int n  = s1.size() , m = s2.size();

    vector<bool> prev(m+1,false) , cur(m+1 , false);

   prev[0] = true;
    for(int j =1 ; j<=m;j++)
        prev[j] = false;


    for(int i = 1 ; i<=n ; i++)
    {
        bool flag = true;
        for(int ii=1;ii<=i;i++) {
            if (s1[ii - 1] != '*') {
                flag = false;
                break;
            }
        }
        cur[0] = flag;

        for(int j=1 ; j<=m ; j++)
        {
            if(s1[i-1] == s2[j-1])  cur[j] = prev[j-1] ;
            else if(s1[i-1] == '*')
                cur[j] = cur[j-1]|| prev[j];
            else
               cur[j] = false;
        }
        prev = cur;
    }
    return prev[m];
}
int main()
{
    string s1 = "ab*cd";
    string s2 = "abdefcd";
    bool result = f(s1,s2);
    if(result)
        cout<<"String s1 and String s2 matched .";
    else
        cout<<"Both the strings don't match at all .";

    return 0;

}

