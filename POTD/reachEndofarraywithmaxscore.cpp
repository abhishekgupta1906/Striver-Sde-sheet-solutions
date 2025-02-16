#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[ind]-max score from ind to n-1

long long findMaximumScore(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> nge(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= arr[st.top()])
        {
            st.pop();
        }
        if (!st.empty())
        {
            nge[i] = st.top();
        }
        else
        {
            nge[i] = n;
        }
        st.push(i);

        /* code */
    }
    long long ans=0;
    int i=0;
    while(i<n){
        if(nge[i]==n){
            ans+=1LL*(n-1-i)*arr[i];
        }
        else{
            ans+=1LL*(nge[i]-i)*arr[i];
        }
        i=nge[i];
    }
    return ans;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {1,3,1,5};
    cout << findMaximumScore(nums);

    return 0;
}