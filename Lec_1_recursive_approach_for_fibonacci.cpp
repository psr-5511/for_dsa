// https://takeuforward.org/data-structure/dynamic-programming-introduction/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(int n , vector<int>& dp)
{
	if(n<=1) return n ;

	if(dp[n]!=-1) return dp[n];

	return dp[n] = f(n-1,dp) + f(n-2,dp);
}
int main()
{
	int n ;cin>>n;

	vector<int> dp(n+1,-1);

	cout<<f(n,dp);

	return 0;
}

// time complexity - O(n)

// space complexity - O(n)