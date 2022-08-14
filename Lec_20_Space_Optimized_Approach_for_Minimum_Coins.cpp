#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int minCoins(vector<int> &arr , int T)
{
	int n = arr.size();

	vector<int> prev(T+1,0) , cur(T+1 , 0);

	for(int i=0;i<=T;i++) 
	{
		if(i%arr[0] == 0)
			 prev[i] = i/arr[0];
		else 
			 prev[i] = 1e9;
	}

	for(int ind = 1 ; ind < n ; ind++)
	{
		for(int target = 0 ; target <=T ; target++)
		{
			int notTaken = 0 + prev[target];

			int taken = INT_MAX ; 

			if(arr[ind] <= target)
				taken = 1 + cur[target - arr[ind]];

			cur[target] = min(notTaken , taken);

		}
		prev = cur;
	}

	int result = prev[T];

	if( result >= 1e9)
		return -1;

	return result;
}

int main()
{
	vector<int> arr = {1,2,3};

	int T = 7 ;
	
	cout<<"The minimum number of coins required to form the target sum is " <<minCoins(arr,T);
	return 0;
}

/*
Time Complexity: O(N*T)

Reason: There are two nested loops

Space Complexity: O(T)

Reason: We are using two external arrays of size ‘T+1’.

*/
