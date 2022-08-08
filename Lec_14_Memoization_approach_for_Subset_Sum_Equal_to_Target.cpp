#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


bool subsetSumUtil(int ind , int target , vector<int> &arr, vector<vector<int>> &dp)
{
	if(target == 0) return true;

	if( ind == 0) return (arr[0] == target);

	bool notTaken = subsetSumUtil(ind -1 , target , arr,dp);

	bool taken = false ; 

	if(arr[ind] <= target) taken = subsetSumUtil(ind - 1 , target - arr[ind] , arr,dp);

	return taken || notTaken;
}

bool subsetSumToK(int n , int k , vector<int> &arr)
{
	vector<vector<int>> dp(n , vector<int> (k+1,-1));

	return subsetSumUtil(n-1,k,arr,dp);
}

int main()
{

	vector<int> arr= {1,2,3,4};

	int k = 4; 

	int n = arr.size();

	if(subsetSumToK(n , k , arr))
		cout <<"Sub set with sum found" << endl;
	else

		cout<<"not found"<<endl;
	
	return 0;
}

// time complexity - O(N*K)

// space complexity - O(N*K) + O(N)