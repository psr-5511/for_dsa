#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

long  coin_change2(vector<int> &arr,int ind , int T,vector<vector<long>> &dp)
{
	if(ind==0)
		return(T%arr[0] == 0);

	if(dp[ind][T] !=-1) return dp[ind][T];

	long  not_take = coin_change2(arr,ind-1 , T,dp);

	long  take = 0;

	if(arr[ind] <= T)
		take = coin_change2(arr,ind, T-arr[ind],dp);

	return dp[ind][T] = not_take + take ;

}

long coin_change2_Util(vector<int> &arr,int T,int n )
{
	vector<vector<long>> dp(n, vector<long> (T+1,-1));

	return coin_change2(arr,n-1 , T , dp);
}

int main()
{
	vector<int> arr = {1,2,3};

	int target = 4;

	int n = arr.size();

	cout<<"The number of ways is :"<<coin_change2_Util(arr,target,n);
	
	return 0;
}


/*

time complexity : O(N*T)

reason : There are N*W states therefore at max N*T new problems will be solved 

space complexity : O(N*T) + O(N)

reason : 2-d array space + recursion stack space of N

*/