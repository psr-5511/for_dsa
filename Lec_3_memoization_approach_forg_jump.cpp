
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int index , vector<int>height, vector<int> &dp)
{
	if(index==0) return 0;

	if(dp[index]!=-1) return dp[index];

	int jump_two = INT_MAX ; 
	int jump_one = solve(index-1,height,dp) + abs(height[index] - height[index-1]);

	if(index>1)
		jump_two = solve(index-2,height,dp) + abs(height[index] - height[index-2]);

	return dp[index] = min(jump_two,jump_one);
}

int main()
{

	vector<int> height{30,10,60,10,60,50};

	int n = height.size();

	vector<int> dp(n,-1);


	cout<<solve(n-1,height,dp);
	return 0;
}

// time complexity - O(n)

// space complexity - O(n)