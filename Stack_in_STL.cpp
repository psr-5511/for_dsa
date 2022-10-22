//
// Created by honey on 11-10-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.pop();

    while (!st.empty())
    {
        cout << st.top() <<" "<<endl;
        st.pop();
    }
    return 0;
}

