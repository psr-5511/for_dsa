#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int mod = (int)1e9 + 7;

int countSubsetsUtil(int index , int target,vector<int> &arr,vector<vector<int>> &dp)
{
	if(index == 0)
	{
		if(target == 0 && arr[0] == 0)
			return 2 ;

		if(target == 0 || target == arr[0])
			return 1 ;

		return 0;
	}

	if(dp[index][target]!=-1) 
		return dp[index][target];

	int not_take = countSubsetsUtil(index-1 , target, arr,dp);

	int take = 0;

	if(arr[index] <= target) 
		take = countSubsetsUtil(index-1,target-arr[index], arr,dp);

	return dp[index][target] = (take + not_take)%mod;
}

int countSubsets(vector<int> &arr , int d)
{
	int n = arr.size();
	int total_sum = 0;
	for(int i = 0; i < arr.size(); i++)
		total_sum += arr[i];


	if(total_sum -d <0) return 0 ;

	if((total_sum-d)%2==1) return 0;

	int s2 = (total_sum - d ) / 2 ; 

	vector<vector<int>> dp(n,vector<int>(s2+1,-1));

	return countSubsetsUtil(n-1 , s2 , arr,dp);
}


int main()
{
	vector<int> arr = {5,2,6,4};

	int d = 3;

	cout<<"The number of subsets found:"<<countSubsets(arr,d);
	
	return 0;
}

// time complexity - O(N*K)

// Reason : There are N*K states therefore atleast N*K new problems will be solved 


// space complexity - O(N*K) + O(N)

// Reason : 2-D array space + recursion stack space 