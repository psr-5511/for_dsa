#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>

int solveUtil(int index , vector<int> &arr , vector<int> &dp)
{
	

	if(index == 0) return arr[index];

	if(index<0) return 0;

	if(dp[index]!=-1) return dp[index];

	int pick = arr[index] + solveUtil(index-2,arr,dp);

	int not_pick = 0 + solveUtil(index-1,arr,dp);

	return dp[index] = max(pick,not_pick);
}

int solve(int n , vector<int> &arr)
{
	vector<int> dp(n,-1);

	return solveUtil(n-1,arr,dp);
}

int main()
{
	vector<int> arr{2,1,4,9};

	int n = arr.size();

	cout<<solve(n,arr);
	return 0;
}

// time complexity - O(n)

// space complexity - O(n)