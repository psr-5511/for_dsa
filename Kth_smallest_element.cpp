#include <iostream>
#include <vector>
#include <map>
using namespace std;


int KthSmallest(map<int, int> m,int k)
{
    int freq=0;
    for(auto it=m.begin();it!=m.end();it++)
    {
        freq+=it->second;

        if(freq>=k)
        {
            return it->first;
        }
    }
    return -1;
}

int main()
{
    
    int n=7;
    int k=1;

    vector<int> arr = {7,0,25,6,16,17,0};

    map<int, int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]+=1;

    }

    int ans = KthSmallest(m,k);

    if(k==1){
    cout << "The " << k << "st smallest element is " << ans
         << endl;
  }
  else if(k==2){
    cout << "The " << k << "nd smallest element is " << ans
         << endl;
  }
  else if(k==3){
    cout << "The " << k << "rd smallest element is " << ans
         << endl;
  }
  else{
    cout << "The " << k << "th smallest element is " << ans
         << endl;
  }

    return 0;
}
