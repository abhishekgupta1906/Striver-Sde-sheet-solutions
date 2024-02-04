#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// find the minimum element in rotation vector
// all elements are unique
int findMin(vector<int> &nums)
{
    int start = 0;
    int end = nums.size()-1;
    int ans=INT32_MAX;
    while(start <=end)
    {
        int mid=start+(end-start)/2;
        if(nums[mid]>=nums[start])
        {
            // left part is sorted
            ans=min(ans,nums[start]);
            // move to right part
            start=mid+1;

        }
        else
        {
            // right part is sorted
            // nums[mid] sirf chlega
            ans=min(ans,min(nums[mid],nums[mid+1]));
            // move to left part
            end=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums={4,5,6,7,0,1,2};
    int ans=findMin(nums);
    cout<<ans;

    return 0;
}