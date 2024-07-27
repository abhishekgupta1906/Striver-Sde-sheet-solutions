#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// prefix[j]-prefix[i]=k;
// prefix[i]=prefix[j]-k
int subarraySum(vector<int> &nums, int k)
{
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
        /* code */
    }

    int ans = 0;
    map<int, int> mp;
    for (int j = 0; j < prefix.size(); j++)
    {
        if ((prefix[j] - k) == 0)
        {
            ans++;
        }

        ans += mp[prefix[j] - k];
        mp[prefix[j]]++;

        /* code */
    }
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {1,2,3};
    int ans = subarraySum(nums,3);
    cout << ans;
    return 0;
}