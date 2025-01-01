#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

int shortestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
        /* code */
    }
    deque<int>dq;
    // for maintaining increasing 
    // jb cumulative sum ght jye 
    // toh usko discard kro kyu ki uska koi fayda,kyuki shortest me hi utna sum mi jyega
    int ans=INT_MAX;
 
    for (int i = 0; i <n; i++)
    {
       
        if(prefix[i]>=k){
            ans=min(ans,i+1);
        }
        while(!dq.empty() && prefix[i]-prefix[dq.front()]>=k){
            int ind=dq.front();
            ans=min(ans,i-ind+1);
            dq.pop_front();
          
        }
        // jb dip hua h pehle ka sara nikal do jb tk increasing na ho
        while(!dq.empty() && prefix[i]<=prefix[dq.back()]){
          dq.pop_back();
        }
        dq.push_back(i);
        /* code */
    }
    return (ans==INT_MAX)?-1:ans;
    


}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {17,85,93,-45,-21};
    int ans = shortestSubarray(nums,150);
    cout << ans;
    return 0;
}