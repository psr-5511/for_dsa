#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


bool subsetSumToK(int n , int k , vector<int> &arr)
{
	vector<bool> prev(k+1 , false) , curr(k+1 , false);

	prev[0] = true;

	if( arr[0] <= k)
		prev[arr[0]] = true;

	

	for (int ind = 1; ind < n; ++ind)
	{
		for (int target = 1; target <=k; ++target)
		{
			bool notTaken = prev[target];

			bool taken = false;

			if(arr[ind] <= target)
				taken = prev[target - arr[ind]];



			curr[target] = taken || notTaken ;
		}

		prev = curr;
	}

	return prev[k];
}
int main()
{
	vector<int> arr = {1,2,3,4};
	int k=4;
	int n = arr.size();

	if(subsetSumToK(n,k,arr))
		cout<<"Subset with given target found";
	else 
		cout<<"Subset with given target not found";
	return 0;
}

// time complexity - O(N*K)

// space complexity - O(K)