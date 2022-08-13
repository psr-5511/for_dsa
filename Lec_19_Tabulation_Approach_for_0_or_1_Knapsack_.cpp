#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int knapsack(vector<int> &wt , vector<int> &val , int n , int W)
{
	// base case 

	vector<vector<int>> dp(n , vector<int>(W+1 ,  0));

	for(int i = wt[0] ; i <= W  ; i++)
		dp[0][i] = val[0];

	for(int ind = 1 ; ind<n ; ind++)
	{
		for(int cap = 0 ; cap <=W ; cap++)
		{
			int notPick = 0 + dp[ind - 1][cap];

			int pick = INT_MIN;

			if(wt[ind] <= cap)
				pick = val[ind] + dp[ind-1][cap-wt[ind]];

			dp[ind][cap] = max(pick , notPick);
		}
	}

	return dp[n-1][W];
}

int main()
{
	vector<int> wt = {1,2,4,5};

	vector<int> val = {5,4,8,6};

	int W = 5;

	int n = wt.size();

	cout<<"The maximum value of items , thief can steal is :"<<knapsack(wt,val , n , W);
	
	return 0;
}

// time complexity : O(N*W)

// reason : there are N*W states therefore at max N*W new problems will be solved 

// space complexity : O(N*W)

// reason : we are using a 2-D array of space N*W