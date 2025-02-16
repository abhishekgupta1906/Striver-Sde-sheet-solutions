#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// dekho iss problem mainly kya sochna ki har element ke right me dekho usse chota within limits wla element se swap kro ,st maintain kr lenge from right ye greedy fail hota h
// main use transitive property ki agar a->b-c ,a->c ,maintain a group of them
vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
{
    int n = nums.size();
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());
    map<int, vector<int>> mp1;
    // this tracks ek group kon kon se element
    map<int, int> mp2;
    // this tracks ye element konsa group ka h
  
    int grp = 0;
    mp1[grp].push_back(arr[0]);
    vector<int>ans(n);
    mp2[arr[0]] = grp;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] <= limit)
        {
            mp1[grp].push_back(arr[i]);
            mp2[arr[i]]=grp;
        }
        else{
            grp++;
            mp1[grp].push_back(arr[i]);
            mp2[arr[i]]=grp;
        }
    }
    for(int i=0;i<n;i++){
        int gp=mp2[nums[i]];
        vector<int>&v=mp1[gp];
        ans[i]=v[0];
        v.erase(v.begin());
    }
    return ans;

}
int main()
{
    // int n,k;
    // cin>>n>>k;
    // vector<int>nums(n);
    // for(int i=0;i<n;i++){
    //     cin>>nums[i];
    // }
    // vector<int>v=lexicographicallySmallestArray(nums,k);
    // for(auto it:v){
    //     cout<<it<<" ";
    // }

    vector<int> nums = {1,7,6,18,2,1};
    vector<int>ans=lexicographicallySmallestArray(nums,3);
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}