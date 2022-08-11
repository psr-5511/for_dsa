#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int findWaysUtil(int ind , int target , vector<int> &arr,vector<vector<int>> &dp)
{
	if(target ==0) return 1 ;

	if(ind == 0) return (arr[ind] == target);

	if(dp[ind][target]!=-1) return dp[ind][target];

	int notTaken = findWaysUtil(ind -1 , target , arr,dp);

	int taken = 0 ;

	if( arr[ind] <= target)
		taken = findWaysUtil(ind-1 , target-arr[ind],arr,dp);

	return dp[ind][target] = taken + notTaken ;
}

int findWays(vector<int> &num , int k)
{
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(k+1,-1));

	return findWaysUtil(n-1, k , num , dp);

}



int main()
{
	vector<int> arr = {1,2,3,3};

	int k = 3;

	cout<<findWays(arr,k)<<endl;
	
	return 0;
}

// time complexity - O(N*K)

// Reason : there are n*k states therefore at max 'N*K' new problems will be solved 


// space complexity - O(N*K) + O(N)

// Reason : we are using a recursion stack space of O(N) and a 2-D array space of O(N*K)