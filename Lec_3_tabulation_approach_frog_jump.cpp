#include<bits/stdc++.h>
using namespace std;
int main()
{

	vector<int> height{30,10,60,10,60,50};

	int n = height.size();

	vector<int> dp(n,-1);

	dp[0] = 0 ;

	for(int index =1 ; index < n ; index++)
	{
		int jump_two = INT_MAX ;

		int jump_one = dp[index-1] + abs(height[index] -height[index-1]);

		if(index>1)
			jump_two = dp[index-2] + abs(height[index] -height[index-2]);

		dp[index] = min(jump_two,jump_one);
	}

	cout <<dp[n-1] ; 
	
	return 0;
}

// time complexity - O(n)

// space complexity - O(n)