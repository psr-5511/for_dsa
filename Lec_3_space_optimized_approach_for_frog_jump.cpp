#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> height{30,10,60,10,60,50};

	int n = height.size();

	int prev = 0 ;

	int prev2 = 0;


	for(int index =1 ; index < n ; index++)
	{
		int jump_two = INT_MAX ;

		int jump_one = prev + abs(height[index] -height[index-1]);

		if(index>1)
			jump_two = prev2 + abs(height[index] -height[index-2]);

		int cur_i = min(jump_two,jump_one);

		prev2 = prev ;

		prev = cur_i;
	}

	cout <<prev ;
	return 0;
}

// time complexity - O(n)
// space complexity - O(1)