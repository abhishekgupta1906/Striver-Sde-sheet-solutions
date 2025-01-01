#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int maximumBeauty(vector<int> &nums, int k)
{
    // sweep line
    int n = nums.size();
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
    {
        int low = nums[i] - k;
        int high = nums[i] + k;
        events.push_back({low, 1});
        events.push_back({high + 1, -1});

        /* code */
    }
    sort(events.begin(),events.end());
    int count=0;
    int maxi=0;
    for (int i = 0; i <events.size(); i++)
    {
        if(events[i].second==1){
            count++;
        }
        else if(events[i].second==-1){
            count--;
        }
        maxi=max(maxi,count);
        /* code */
    }
    return maxi;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={1,1,1,1};
    int ans=maximumBeauty(nums,10);
    cout<<ans;
    return 0;
}