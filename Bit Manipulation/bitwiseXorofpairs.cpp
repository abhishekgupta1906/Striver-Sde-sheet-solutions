#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    int ans = nums2[0];
    for (int i = 1; i < nums2.size(); i++)
    {
        ans=ans^nums2[i];
        /* code */
    }
    int val=nums1[0];
    for (int i =1; i < nums1.size(); i++)
    {
        val=val^nums1[i];
       
        /* code */
    }
    if(nums1.size() % 2==1 && nums2.size()==1){
        return (ans^val);
    }
    else if(nums1.size() % 2==1 && nums2.size() %2==0){
        return ans;
    }
     else if(nums1.size() % 2==0 && nums2.size() %2==1){
        return val;
    }
    return 0;

   
}
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int>nums1(n);
    vector<int>nums2(m);
    for (int i = 0; i<n; i++)
    {
        cin>>nums1[i];
        /* code */
    }
    for (int i = 0; i <m; i++)
    {
        cin>>nums2[i];
        /* code */
    }
    int ans=xorAllNums(nums1,nums2);
    cout<<ans<<'\n';

    
    
    return 0;
}
