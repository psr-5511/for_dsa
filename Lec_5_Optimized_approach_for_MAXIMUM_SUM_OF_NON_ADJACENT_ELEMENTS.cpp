#include<bits/stdc++.h>
using namespace std;


int solve(int  n , vector<int> &arr)
{
	int prev = arr[0] ; 

	int prev2 = 0 ;

	for (int i = 1; i < n; ++i)
	{
		int pick = arr[i] ; 

		if(i>1)
			pick += prev2;

		int not_pick = 0 + prev ; 

		int cur_i = max(pick , not_pick) ; 

		prev2 = prev ;

		prev = cur_i ; 
	}

	return prev ; 
}
int main()
{
	vector<int> arr{2,1,4,9};

	int n = arr.size();
	cout<< solve(n,arr);
	return 0;
}

// time complexity - O(n)
// space complexity - O(1)