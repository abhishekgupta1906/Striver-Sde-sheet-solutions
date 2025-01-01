#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define m 1000000007

int mod_mul(int a, int b)
{
    return (a % m * b % m) % m;
}
vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    int n = nums.size();
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        st.insert({nums[i], i});
        /* code */
    }

    vector<int> ans(n);
    int val = k;
    while (val > 0)
    {
        auto it = st.begin();
        int v = it->first;
        int ind = it->second;
        st.erase(it);
        int new_val = mod_mul(v, multiplier);
        st.insert({new_val, ind});
    }
    while(!st.empty()){
        auto it=st.begin();
        int ind=it->second;
        int new_val=it->first;
        ans[ind]=(new_val)%m;
        st.erase(it);
    }
    return ans;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}