#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
// given a sorted array of integers,where each element appears twice,one element is unique
// find that element
// jidhar duplicate mila wo sorted

int singleNonDuplicate(vector<int>& nums)
{
   int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        // Ensure mid is at an even index
        if (mid % 2 == 1) {
            mid--;
        }

        if (nums[mid] == nums[mid + 1]) 
        {
            start = mid + 2;
            // right part is sorted
            // 3,3,7,7,10,11,11
            //1,1,2,2,3,3,4,4,8
        }
        else 
        {
            end = mid;
        }
    }

    return nums[start];
        
}
int main()
{
    vector<int>nums={1,1,2,3,3,4,4,8,8};
    int ans=singleNonDuplicate(nums);
    cout<<ans;
    
return 0;
}