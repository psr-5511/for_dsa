#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int minCoins(vector<int> &arr , int T)
{
	int n = arr.size();

	vector<vector<int>> dp(n, vector<int> (T+1,0));

	for(int i=0;i<=T;i++) 
	{
		if(i%arr[0] == 0)
			 dp[0][i] = i/arr[0];
		else 
			 dp[0][i] = 1e9;
	}

	for(int ind = 1 ; ind < n ; ind++)
	{
		for(int target = 0 ; target <=T ; target++)
		{
			int notTaken = 0 + dp[ind-1][target];

			int taken = INT_MAX ; 

			if(arr[ind] <= target)
				taken = 1 + dp[ind][target - arr[ind]];

			dp[ind][target] = min(notTaken , taken);

		}
	}

	int result = dp[n-1][T];

	if( result >= 1e9)
		return -1;

	return result;
}

int main()
{
	vector<int> arr = {1,2,3};

	int T = 7 ;
	
	cout<<"The minimum number of coins required to form the target sum is " <<minCoins(arr,T);
	return 0;
}

/*
Time Complexity: O(N*T)

Reason: There are two nested loops

Space Complexity: O(N*T)

Reason: We are using an external array of size ‘N*T’. Stack Space is eliminated.

*/
