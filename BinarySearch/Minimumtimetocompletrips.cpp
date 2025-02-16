#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// check(mid)-can i make >=k trips in less<=k
bool check(vector<int> &time,long long mid, int k)
{
    int trips = 0;
    for (int i = 0; i < time.size(); i++)
    {
        trips += (mid) / time[i];
        /* code */
    }
    return trips >= k;
}
long long minimumTime(vector<int> &time, int totalTrips)
{
    int n = time.size();
    long long low = 1;
    int maxi=*max_element(time.begin(),time.end());
    long long high=maxi*totalTrips;
    long long ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (check(time, mid, totalTrips))
        {
            ans = mid;
            high=mid-1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> time = {1, 2, 3};
    cout << minimumTime(time, 5);

    return 0;
}