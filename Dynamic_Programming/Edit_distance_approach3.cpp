#include<bits/stdc++.h>
using namespace std;

void EditDistDP(string str1,string str2)
{
    int len1=str1.length();
    int len2=str2.length();

    // create a dp array to memoize the result of previous computations

    int DP[2][len1+1];

    // to fill the dp array with 0

    memset(DP,0,sizeof(DP));

    // base condition when second string is empty then we remove all characters

    for(int i=0;i<=len1;i++) 
    {
        DP[0][i] = i;
    }


    // start filling the DP
    // this loop run for every character in the second string 


    for(int i=1;i<=len2;i++)
    {
        // this loop compares the character from the second string with the first string characters
        for(int j=0;j<=len1;j++)
        {
            // if first string is empty then we have to perform add character operation  to get second string
        

            if(j==0) 
                DP[i%2][j]=i;
                // if the character for both the strings is same then we dont have to perform operation . here i%2 is for the bound row number
            else if(str1[j-1]==str2[i-1])
                DP[i%2][j]=DP[(i-1)%2][j-1];

                // if the character from both the strings is not same  then we take the minimum from three specified operation
            else 
                DP[i%2][j]= 1+min(DP[(i-1)%2][j],min(DP[i%2][j-1],DP[(i-1)%2][j-1]));
        }
    }
    // after complete fill the array
    // if len2 is even then we end up in the 0th row else we end up in the 1 th row 
    // so we take len2%2  to get row

    cout<<DP[len2%2][len1]<<endl;

}

int main()
{
    string str1="food";
    string str2 ="money";
    EditDistDP(str1,str2);    
    return 0;
}


// Time complexity --> O(m X n)
// space complexity --> O(m)
