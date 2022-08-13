#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int countSubsetsUtil(int target , vector<int> &arr)
{
	int n = arr.size();

	vector<vector<int>> dp(n , vector<int>(target+1,0));

	if(arr[0] == 0) dp[0][0]=2;

	else
		dp[0][0] =1;

	if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]]=1;

	for(int i = 1 ; i< n ; i++)
	{
		for(int tar = 1 ; tar<=target;tar++)
		{
			int notTaken = dp[i-1][target];

			int taken = 0 ;

			if(arr[i] <= target)
				taken = dp[i-1][target-arr[i]];

			dp[i][target] = taken + notTaken;
		}
	}

	return dp[n-1][target];

}

int countSubsets(vector<int> &arr, int n , int d)
{
	int total_sum = 0;
	for(int i=0;i<n;i++)
		total_sum += arr[i];

	if(total_sum - d <0 || (total_sum -d)%2) return 0;

	return countSubsetsUtil((total_sum-d) / 2 , arr);
}

int main()
{

	vector<int> arr = {5,2,6,4};

	int d = 3;

	cout<<"The number of subsets found were :"<<countSubsets(arr,4,d);
	
	return 0;
}

// time complexity - O(N*K)

// reason : There are N*K states therefore atleast N*K new problems will be solved 

// space complexity - O(N*K)

// reason : recursion stack space is gone 