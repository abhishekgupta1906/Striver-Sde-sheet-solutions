#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
// array of duplicate values
// approach unsorted half eliminate kro and sorted half me check kro
// find a solution with distinct 
// check where this soln fails
// add those conditions


bool search(vector<int>& nums, int target) 
{
    int start = 0;
    int end = nums.size() - 1;
    
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target)
        {
            return true;
        }
        if(nums[mid]==nums[start] && nums[mid]==nums[end])
        {
            start++;
            end--;
            continue;
            // 3 3 1 3 3 3 3
        }
        
        if (nums[mid] >= nums[start])
        {
            // Left part is sorted
            if (target >= nums[start] && target < nums[mid])
            {
                // Target is in the left sorted part
                // element exist
                end=mid-1;
                
                
            }
            else
            {
                // Target is in the right unsorted part
                start = mid + 1;
            }
        }
        else
        {
            // Right part is sorted
            if (target > nums[mid] && target <= nums[end])
            {
                // Target is in the right sorted part
                // element exist
                start=mid+1;
              
            }
            else
            {
                // Target is in the left unsorted part
                end = mid - 1;
            }
        }
    }
    
    return false;
}
int main()
{
   vector<int> v = {1,0,1,1,1};
   int a=search(v,0);
   cout<<a;
    
    
   

           
    
    
return 0;
}