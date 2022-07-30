// https://takeuforward.org/data-structure/dynamic-programming-introduction/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int n = 5;
	int prev2 = 0 ; 
	int prev = 1;

	for (int i = 2; i <= n; ++i)
	{
		int cur_i = prev2 + prev ;

		prev2 = prev;
		prev = cur_i;
	}

	cout<<prev ;

	return 0;
}

// time complexity - O(n)

// space complexity - O(1)