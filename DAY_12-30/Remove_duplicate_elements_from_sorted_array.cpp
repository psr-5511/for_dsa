#include<bits/stdc++.h>
using namespace std;
#define endl "\n" 

class Solution{
    public:
    int removeDuplicates(vector<int> &nums)
    {
        if(nums.size() == 0) return 0 ;

        int i = 0 ;

        for (int j = 1; j < nums.size(); ++j)
        {
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1 ;
        
    }
};

int main() 
{

    vector<int> v1 = {1,1,2};

    Solution obj ;
    int result1= obj.removeDuplicates(v1);

    cout << result1 << endl;

    vector<int> v2 = {0,0,1,1,1,2,2,3,3,4};

    int result2 = obj.removeDuplicates(v2);

    cout << result2 << endl;

    return 0;
}

// time complexity - O(n)

//space complexity -> O(1)