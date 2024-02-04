#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// peak elements which is greater than neighbours
int findPeakElement(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int n = nums.size();
    int ans = -1;  // Initialize ans with a default value

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if mid is a peak
        if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
            ans = mid;
            break;
        }

        // If the element to the right is greater, move towards the right
        if (nums[mid] < nums[mid + 1]) {
            start = mid + 1;
        } else {
            // Otherwise, move towards the left
            end = mid - 1;
        }
    }

    return ans;
}
int main()
{
    vector<int>v={1,2,1,3,5,7};
    int index=findPeakElement(v);
    cout<<index;

    return 0;
}