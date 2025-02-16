#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int maxScore(string s)
{
    int maxi = 0;
    int n = s.length();
    vector<int> cnt0(n, 0);
    vector<int> cnt1(n, 0);
    cnt0[0] = (s[0] == '0') ? 1 : 0;
    cnt1[0] = (s[0] == '1') ? 1 : 0;
    for (int i = 1; i < n; i++)
    {
        cnt0[i] = ((s[i] == '0') ? 1 : 0) + cnt0[i - 1];
        cout << cnt0[i];
        cnt1[i] = ((s[i] == '1') ? 1 : 0) + cnt1[i - 1];
    }
    for (int k = 1; k <= n - 1; k++)
    {
        // cnt 0 till ith k-1
        // cnt 1 from k to n-1
        int val1 = cnt0[k - 1];
        int val2 = cnt1[n - 1] - cnt1[k - 1];
        maxi = max(maxi, val1 + val2);
    }
    return maxi;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s="011101";
    cout<<maxScore(s);
    return 0;
}