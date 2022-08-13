#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int knapsack(vector<int> &wt , vector<int> &val , int n , int W)
{
	// base case 

	vector<int> prev(W+1 ,0) ;

	for(int i = wt[0] ; i <= W  ; i++)
		prev[i] = val[0];

	for(int ind = 1 ; ind<n ; ind++)
	{
		for(int cap = W ; cap>=0 ; cap--)
		{
			int notPick = 0 + prev[cap];

			int pick = INT_MIN;

			if(wt[ind] <= cap)
				pick = val[ind] + prev[cap-wt[ind]];

			prev[cap] = max(pick , notPick);
		}
		
	}

	return prev[W];
}

int main()
{
	vector<int> wt = {1,2,4,5};

	vector<int> val = {5,4,8,6};

	int W = 5;

	int n = wt.size();

	cout<<"The maximum value of items , thief can steal is :"<<knapsack(wt,val , n , W);
	
	return 0;
}

// time complexity : O(N*W)

// reason : there are N*W states therefore at max N*W new problems will be solved 

// space complexity : O(W)

// reason :We are using an external array of size ‘W+1’ to store only one row.