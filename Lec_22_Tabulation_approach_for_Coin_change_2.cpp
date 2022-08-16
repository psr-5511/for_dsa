#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

long coin_change2(vector<int> &arr , int ind , int T, int n)
{
	vector<vector<long>> dp(n,vector<long> (T+1,0));
	for(int i = 0 ; i <= T ; i++)
		if(i%arr[0] == 0)
			dp[0][i]= 1;

	for(int ind = 1 ; ind <n ; ind++)
	{
		for(int target = 0 ; target <= T ; target++)
		{
			long not_take = dp[ind-1][target];

			long take = 0;

			if(arr[ind]<=target)
				take = dp[ind][target-arr[ind]];

			dp[ind][target] = not_take+ take;
		}
	}

	return dp[n-1][T];

}

int main()
{

	vector<int> arr = {1,2,3};

	int target = 4;

	int n = arr.size();

	cout<<"The total number of ways:"<<coin_change2(arr,n-1,target,n);
	
	return 0;
}


/*

time complexity : O(N*T)

reason : There are N*W states therefore at max N*T new problems will be solved 

space complexity : O(N*T) 

reason : 2-d array space 


*/