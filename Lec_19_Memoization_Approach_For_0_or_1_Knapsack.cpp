#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int knapsackUtil(vector<int> &wt,vector<int> &val ,int ind , int W , vector<vector<int>> &dp)
{
	if(ind==0)
	{
		if(wt[0] <= W)
			return val[0];
		else 
			return 0;
	}

	if(dp[ind][W] != -1) return dp[ind][W];

	int notPick = 0 + knapsackUtil(wt , val,ind-1,W,dp);

	int pick = INT_MIN ;

	if(wt[ind] <= W)
		pick = val[ind] + knapsackUtil(wt,val,ind-1,W-wt[ind],dp);

	return dp[ind][W] = max(pick,notPick);
}

int knapsack(vector<int> &wt , vector<int> &val ,  int W , int n)
{
	vector<vector<int>> dp(n, vector<int> (W+1,-1));

	return knapsackUtil(wt , val, n-1 , W , dp);
}

int main()
{

	vector<int> wt = {1,2,4,5};

	vector<int> val = {5,4,8,6};

	int W =5;

	int n = wt.size();
	
	cout<<"The maximum value of items thief can steal is :"<<knapsack(wt,val,W,n);
	return 0;
}

// time complexity : O(N*W)

// reason : There are N*W states therefore at max 'N*W' new problems will be solved 


// space complexity : O(N*W) + O(N)

// reason : we are using a 2-D array of size N*W  and recursion stack space of N