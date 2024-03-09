#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// leetcode 2616
// find differnce max hona chaiye usko minimize krna h
bool check(vector<int> &nums, int p,int maxdifferce)
{
    int n=nums.size();
    int lastposition=0;
    int pairs=0;
    for (int i =1; i <n; i++)
    {
        if(i==lastposition)
        {
            continue;
        }
        if(abs(nums[i]-nums[lastposition])<=maxdifferce)
        {
            lastposition=i+1;
            pairs++;
            if(pairs==p)
            {
                return true;
            }
            
        }
        else{
            lastposition++;
        }
        /* code */
    }
    return false;
    
   
}
// leetcode 2327
int minimizeMax(vector<int> &nums, int p)
{
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int low=0;
    int high=nums[n-1]-nums[0];
    // range
    int ans=0;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(check(nums,p,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        /* code */
    }
    return ans;
}
int main()
{
    vector<int>nums={4,2,1,2};
    int ans=minimizeMax(nums,1);
    cout<<ans;

    return 0;
}