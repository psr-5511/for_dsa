#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int f(vector<int> &wt , vector<int> &val , int n , int W)
{
	vector<vector<int>> dp(n, vector<int>(W+1,0));

	for(int i = wt[0] ; i<=W ; i++)
		dp[0][i] = (i/wt[0]) * val[0];

	for(int ind = 1 ; ind < n ; ind++)
	{
		for(int i=0 ; i<=W ; i++)
		{
			int not_take = 0 + dp[ind-1][i];

			int take = INT_MIN;

			if(wt[ind] <= i)
				take = val[ind] + dp[ind][i-wt[ind]];

			dp[ind][i] = max(take,not_take);
		}

	}


	return dp[n-1][W];
}

int main()
{
	vector<int> wt = {2,4,6};

	vector<int> val = {5,11,13};

	int W = 10;

	int n = wt.size();

	cout<<"The Maximum value of items, thief can steal is " <<f(wt,val,n,W);
	
	return 0;
}

/*

time complexity : O(N*W)

reason: there are N*W states therefore at max N*W new problems will be solved .


space complexity : O(N*W) 

reason :  a 2-D array space of N*W

*/