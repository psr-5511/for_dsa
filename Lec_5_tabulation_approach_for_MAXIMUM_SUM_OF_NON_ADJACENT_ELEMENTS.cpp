#include<bits/stdc++.h>
using namespace std;
// #define vi vector<int>




int solveUtil(int n , vector<int>& arr, vector<int> &dp)
{
	dp[0] = arr[0];

	for (int i = 1; i < n; ++i)
	{
			int pick = arr[i];

			if(i>1)
				pick+= dp[i-2];

			int not_pick = 0 + dp[i-1];

			dp[i] = max(pick,not_pick);
	}

	return dp[n-1];
}

int solve(int n, vector<int>& arr)
{
		vector<int> dp(n,-1);
		return solveUtil(n,arr,dp);
}

int main()
{
	vector<int> arr{2,1,4,9};
	int n=arr.size();
	cout<<solve(n,arr);
	
	return 0;
}