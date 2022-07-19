// Leetocode 807

// https://leetcode.com/problems/max-increase-to-keep-city-skyline/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> columns;
        vector<int> rows;
        
        for(int i=0; i<grid[0].size(); i++){
            int maxi = INT_MIN;
            for(int j=0; j<grid.size(); j++){
                maxi = max(maxi, grid[j][i]);
            }
            columns.push_back(maxi);
        }
        
        for(int i=0; i<grid.size(); i++){
            int num = *max_element(grid[i].begin(), grid[i].end());
            rows.push_back(num);
        }
        
        int sum = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                int col = i;
                int row = j;
                int val = min(columns[col], rows[row]);
                sum += val - grid[i][j];
                grid[i][j] = val;
            }
        }
        return sum;    
    }
};
int main() 
{

    vector<vector < int >> grid  {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};

    Solution obj ;

    int result = obj.maxIncreaseKeepingSkyline(grid);

    cout << result << endl;



    return 0;
}