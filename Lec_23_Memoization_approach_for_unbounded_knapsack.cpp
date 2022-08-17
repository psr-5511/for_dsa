#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int f(vector<int> &wt , vector<int> &val , int ind , int W,vector<vector<int>> &dp)
{
	if(ind ==0)
		return (W/wt[ind] ) * val[0];

	if(dp[ind][W] != -1) return dp[ind][W];

	int not_take = 0 + f(wt,val,ind-1,W,dp);

	int take = INT_MIN;

	if(wt[ind] <= W)
		take = val[ind] + f(wt,val,ind,W-wt[ind],dp);

	return dp[ind][W]=max(take,not_take);
}

int unbounded(vector<int> &wt , vector<int>val , int n , int W)
{
	vector<vector<int>> dp(n,vector<int> (W+1,-1));

	return f(wt,val,n-1,W,dp);
}

int main()
{

	vector<int> wt = {2,4,6};

	vector<int> val = {5,11,13};

	int W = 10;

	int n = wt.size();

	cout <<"The maximum value of items the thief can steal is :"<<unbounded(wt,val,n,W);
	
	return 0;
}

/*

time complexity : O(N*W)

reason: there are N*W states therefore at max N*W new problems will be solved .


space complexity : O(N*W) + O(N)

reason : we are using a recursion stack space of N and a 2-D array space of N*W



*/