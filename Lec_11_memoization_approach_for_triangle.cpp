#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int triangle_sum(int i , int j , vector<vector<int>>& triangle,int n,vector<vector<int>>& dp)
{
	if(i==n-1) return triangle[i][j];

	if(dp[i][j] != -1) return dp[i][j];

	int down = triangle[i][j]+triangle_sum(i+1,j,triangle,n,dp);

	int diagonal = triangle[i][j]+triangle_sum(i+1,j+1 , triangle,  n,dp);

	return dp[i][j] = min(diagonal,down);

}


int minimumPathSum(vector<vector<int>> triangle, int n )
{
	vector<vector<int>> dp(n , vector<int>(n,-1));

	return triangle_sum(0,0,triangle,n,dp);

}

int main()
{
	vector<vector<int>>  triangle{{1},
                                 {2,3},
                                 {3,6,7},
                                 {8,9,6,10}};
                            
  int n = triangle.size();

  cout <<minimumPathSum(triangle,n);
	
	return 0;
}

// Time Complexity: O(N*N)

// Reason: At max, there will be (half of, due to triangle) N*N calls of recursion.

// Space Complexity: O(N) + O(N*N)

// Reason: We are using a recursion stack space: O((N), where N is the path length and an external DP Array of size ‘N*N’.