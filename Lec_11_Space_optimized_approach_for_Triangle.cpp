#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int triangle_sum(vector<vector<int>> &triangle , int n )
{
    

    vector<int> first(n,-1) ; 
    for(int j = 0 ; j < n ; j++)
        first[j] = triangle[n-1][j];

    
    for(int i = n-2 ; i>=0 ; i--)
    {
        vector<int> curr(n,-1) ;

        for(int j=i;j>=0;j--)
        {
            int down = triangle[i][j] + first[j];
            int diagonal = triangle[i][j] + first[j+1];

            curr[j] = min(diagonal,down);
        }

        first = curr;
    }

    return first[0];
}

int main()
{
    vector<vector<int>> triangle = {{1},
    {2,3},
    {3,6,7},
    {8,9,6,10}
};

int n = triangle.size();
cout<<triangle_sum(triangle , n);

return 0;
}

// Time Complexity: O(N*N)

// Reason: There are two nested loops

// Space Complexity: O(N)

// Reason: We are using an external array of size ‘N’ to store only one row.