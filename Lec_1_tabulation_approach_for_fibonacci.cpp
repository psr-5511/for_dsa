//   https://takeuforward.org/data-structure/dynamic-programming-introduction/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int n ; cin>>n;

	vector<int> dp(n+1,-1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i]  = dp[i-1] + dp[i-2] ; 

	}

	cout<<"Factorial of "<<n<<" is:"<<" "<<dp[n];

	return 0;
}

// time complexity - O(n)

// space complexity - O(n)