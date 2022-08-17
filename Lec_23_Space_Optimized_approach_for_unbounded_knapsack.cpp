#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int f(vector<int> &wt , vector<int> &val , int n , int W)
{
	vector<int> prev(W+1,0);

	for(int i = wt[0] ; i<=W ; i++)
		prev[i] = (i/wt[0]) * val[0];

	for(int ind = 1 ; ind < n ; ind++)
	{
		for(int i=0 ; i<=W ; i++)
		{
			int not_take = 0 + prev[i];

			int take = INT_MIN;

			if(wt[ind] <= i)
				take = val[ind] + prev[i-wt[ind]];

			prev[i] = max(take,not_take);
		}

	}


	return prev[W];
}

int main()
{
	vector<int> wt = {2,4,6};

	vector<int> val = {5,11,13};

	int W = 10;

	int n = wt.size();

	cout<<"The Maximum value of items, thief can steal is " <<f(wt,val,n,W);
	
	return 0;
}

/*

time complexity : O(N*W)

reason: there are N*W states therefore at max N*W new problems will be solved .


space complexity : O(W) 

Reason: We are using an external array of size ‘W+1’ to store only one row.


*/