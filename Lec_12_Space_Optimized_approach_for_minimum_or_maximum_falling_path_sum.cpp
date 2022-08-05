#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> prev( m , 0 ) , cur(m , 0);
	for(int j=0 ; j<m ; j++)
		prev[j] = matrix[0][j];


	for(int i = 1 ; i< n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			int up = matrix[i][j] + prev[j];

			int ld = matrix[i][j];
			if(j-1>=0)
				ld += prev[j-1];

			else

				ld += -1e9;

			int rd = matrix[i][j];


			if(j+1<m)
				rd += prev[j+1];

			else
				rd += -1e9;


			cur[j] = max(up,max(ld,rd));
		}

		prev = cur;
	}


	int maxi = INT_MIN;

	for( int j = 0 ; j< m ; j++)
	{
		maxi = max(maxi , prev[j]);
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

// time complexity - O(N*M)

// space complexity - O(M) + O(M)