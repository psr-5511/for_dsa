#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int findWays(vector<int> &num,int k)
{
	int n = num.size();

	vector<int> prev(k+1,0) , cur(k+1 , 0);

	for(int i = 0; i < n; i++)
		prev[0] = 1 , cur[0] = 1;

	if(num[0]<=k)
		prev[num[0]] = 1;

	for(int ind = 1 ; ind<n ; ind++)
	{
		for(int target = 1; target <=k; ++target)
		{
			int notTaken = prev[target];

			int taken = 0;

			if(num[ind] <= target)

				taken = prev[target -num[ind]];

			cur[target] = notTaken + taken;
		}

		prev = cur;
	}

	return prev[k];
}

int main()
{
	vector<int> arr = {1,2,2,3};

	int k = 3;

	cout<<"The number of subsets found:"<<findWays(arr,k);
	
	return 0;
}

// time complexity - O(N*K)

// space complexity - O(K)