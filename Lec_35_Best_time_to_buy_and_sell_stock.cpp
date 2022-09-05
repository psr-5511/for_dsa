//
// Created by honey on 03-09-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int maximum_profit(vector<int> &arr)
{
    int max_profit = 0 ;
    int mini = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        int curr_profit = arr[i] - mini ;
        max_profit = max(max_profit , curr_profit);
        mini = min(mini,arr[i]);
    }
    return max_profit;
}
int main()
{
    vector<int> Arr  ={7,1,5,3,6,4};
    cout<<"The maximum profit by selling the stocks :"<<maximum_profit(Arr);
    return 0;

}

/*
     Time Complexity: O(N)

    Reason: We are performing a single iteration

    Space Complexity: O(1)

    Reason: No extra space is used.
*/

