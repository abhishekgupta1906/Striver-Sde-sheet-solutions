#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    // crux of the problem is to find the minimum subarray sum of size n-k
    int n = cardPoints.size();
    int len = n - k;
    vector<long long> prefix(n, 0);
    prefix[0] = cardPoints[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = cardPoints[i] + prefix[i - 1];
        /* code */
    }
    long long mini = prefix[len - 1];
    for (int i = 1; i <= n - len; i++)
    {
        int j = i + len - 1;
        mini = min(mini, prefix[j] - prefix[i-1]);
        /* code */
    }
    // ye nhi lena h
    if(mini=prefix[n-1]){
        return mini;
    }
    int ans=prefix[n-1]-mini;
    return ans;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i = 0; i <n; i++)
    {
        cin>>nums[i];
        /* code */
    }
    cout<<maxScore(nums,k);
    
 
    return 0;
}