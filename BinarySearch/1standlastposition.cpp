#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// given a sorted array find the first and last position of target
vector<int> searchRange(vector<int> &nums, int target)
{
     vector<int> result(2, -1);

    // Find lower bound
    auto lower = lower_bound(nums.begin(), nums.end(), target);

    // Check if the target is not found or if lower is at the end
    if (lower == nums.end() || *lower != target) 
    {
        return result;
    }

    // Find upper bound
    auto upper =upper_bound(nums.begin(), nums.end(), target);

    // Set the result
    result[0] =distance(nums.begin(), lower);
    result[1] =distance(nums.begin(), upper) - 1;

    return result;

   

}
int main()
{
    vector<int>nums={5,7,7,8,8,10};
    vector<int>ans=searchRange(nums,8);

    return 0;
}