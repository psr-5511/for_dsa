#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> dp(n ,vector<int> (m,-1));

	for(int j=0 ; j<m ; j++)
		dp[0][j] = matrix[0][j];


	for(int i = 1 ; i< n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			int up = matrix[i][j] + dp[i-1][j];

			int ld = matrix[i][j];
			if(j-1>=0)
				ld += dp[i-1][j-1];

			else

				ld += -1e9;

			int rd = matrix[i][j];


			if(j+1<m)
				rd += dp[i-1][j+1];

			else
				rd += -1e9;


			dp[i][j] = max(up,max(ld,rd));
		}
	}


	int maxi = INT_MIN;

	for( int j = 0 ; j< m ; j++)
	{
		maxi = max(maxi , dp[n-1][j]);
	}

	return maxi;
}

int main()
{
	vector<vector<int> > matrix{{1,2,10,4},
	{100,3,2,1},
	{1,1,20,2},
	{1,2,2,1}};

	cout<<getMaxPathSum(matrix);
	return 0;
}