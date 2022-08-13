#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int countSubsetsUtil(int target , vector<int> &arr)
{
	int n = arr.size();

	 vector<int> prev(target+1,0) , cur(target+1,0);

	if(arr[0] == 0) prev[0]=2;

	else
		prev[0] =1;

	if(arr[0] != 0 && arr[0] <= target) prev[arr[0]]=1;

	for(int i = 1 ; i< n ; i++)
	{
		for(int tar = 1 ; tar<=target;tar++)
		{
			int notTaken = prev[target];

			int taken = 0 ;

			if(arr[i] <= target)
				taken = prev[target-arr[i]];

			cur[target] = taken + notTaken;
		}

		prev = cur;
	}

	return prev[target];

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

// space complexity - O(K)

// reason :  We are using an external array of size ‘K+1’ to store only one row.