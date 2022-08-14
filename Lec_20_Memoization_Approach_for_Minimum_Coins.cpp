#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int minCoins(vector<int> &arr , int ind , int T , vector<vector<int>> &dp)
{
	if(ind == 0)
	{
		if(T%arr[0] == 0) return T/arr[0];

		else return 1e9;
	}

	if(dp[ind][T]!= -1) return dp[ind][T];

	int notTaken = 0  + minCoins(arr,ind-1,T,dp);

	int taken = 1e9;

	if(arr[ind] <= T)
		taken = 1 + minCoins(arr , ind , T - arr[ind],dp);

	return dp[ind][T]=min(notTaken,taken);
}

int minCoinsUtil(vector<int> &arr , int T)
{
	int n = arr.size();
	vector<vector<int>> dp(n,vector<int> (T+1,-1));

	return minCoins(arr , n-1 , T , dp);
}



int main()
{
	vector<int> arr = {1,2,3};
	int T = 7;

	cout<<minCoinsUtil(arr,T);
	return 0;
}

/*

Time Complexity: O(N*T)

Reason: There are N*T states therefore at max ‘N*T’ new problems will be solved.

Space Complexity: O(N*T) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).

*/