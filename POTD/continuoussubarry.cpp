#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
long long continuousSubarrays(vector<int> &nums)
{
    //    max and minium maintain krna hoga
    int i = 0;
    int j = 0;
    int n = nums.size();
    set<pair<int, int>> st;
    long long ans = 0;
    while (j < n)
    {
        st.insert({nums[j], j});
        auto it = st.begin();
        int mini = it->first;
        int maxi = st.rbegin()->first;
        while (i <= j && maxi - mini > 2)
        {
            st.erase({nums[i], i});
            i++;
            it = st.begin();
            mini = it->first;
            maxi = st.rbegin()->first;
        }
        ans += j - i + 1;
        j++;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = continuousSubarrays(nums);
    cout << ans;
    return 0;
}