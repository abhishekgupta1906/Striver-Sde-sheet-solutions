#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// check(mid)-can i make max balls <=mid using atmost k operations
bool check(vector<int> &nums, int k, int mid)
{
    int op = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= mid)
        {
            if (nums[i] % mid == 0)
            {
                op += (nums[i] / mid) - 1;
            }
            else
            {
                op += nums[i] / mid;
            }
        }
        /* code */
    }
    return op <= k;
}
int minimumSize(vector<int> &nums, int maxOperations)
{
    int ans = 0;
    int low = 0;
    int high = accumulate(nums.begin(), nums.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(nums, maxOperations, mid))
        {
            ans = mid;
            high = mid - 1;
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
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        /*code */
        cin >> nums[i];
    }
    cout << minimumSize(nums, k);

    return 0;
}