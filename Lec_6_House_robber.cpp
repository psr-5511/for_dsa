#include<bits/stdc++.h>
using namespace std;

#define ll long long int


ll solve(vector<int> &arr)
{
	int n = arr.size();

	ll prev = arr[0];

	ll prev2 = 0;

	for (int i = 1; i < n; ++i)
	{
		ll pick = arr[i] ;

		if(i>1)
			pick += prev2;

		ll not_pick = 0 + prev;

		ll cur_i = max(pick,not_pick);

		prev2 = prev;

		prev = cur_i;
	}

	return prev;
}

ll robStreet(int n , vector<int> &arr)
{
	vector<int> arr1;
	vector<int> arr2;


	if(n==1) return arr[0];

	for (int i = 0; i < n; ++i)
	{
		if(i!=0) arr1.push_back(arr[i]);

		if(i!=n-1) arr2.push_back(arr[i]);
	}

	// Space Complexity: O(1)

	ll ans1 = solve(arr1);

	ll ans2 = solve(arr2);

	return max(ans1 , ans2);
}



int main()
{
	vector<int> arr{1,5,1,2,6};
	int n=arr.size();
	cout<<robStreet(n,arr);
	
	return 0;
}

// Time Complexity: O(N )

// Space Complexity: O(1)