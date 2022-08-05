#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int f(int i , int j , vector<vector<int>> &mat,int m , vector<vector<int>> &dp)
{
	if(j<0 || j>=m) return -1e9;
	
	if(i==0) return mat[0][j];

	if(dp[i][j] !=-1) return dp[i][j];
	int up = mat[i][j] + f(i-1,j,mat,m,dp);

	int ld = mat[i][j] + f(i-1 ,j-1 , mat,m,dp);

	int rd = mat[i][j] + f(i-1,j+1 , mat , m,dp);

	return dp[i][j] = max(up,max(ld,rd));

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> dp(n,vector<int>(m,-1));
	int maxi = INT_MIN;

	for(int j = 0 ; j < m ; j++)
	{
		int ans = f(n-1 , j , matrix , m,dp);
		maxi = max(maxi , ans) ;
	}

	return maxi ;
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