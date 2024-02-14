#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// given two sorted arrays find median of two sorted arrays
// tc-O(log(n+m))
// no need to merge ,just follow the symmetery
// if size1 + size2 is even,then we can divide the resultant array into two parts
// Now we have to only check in left part how many elements from array1 and array2
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
   int n1 = nums1.size();
    int n2 = nums2.size();

    // Assuming nums1 is smaller
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int left = (n1 + n2 + 1) / 2;
    int start = 0;
    int end = n1;
    double ans;

    while (start <= end) {
        int mid1 = (start + end) / 2;
        int mid2 = left - mid1;
           // if(mid1-1>=0 && mid1<n)
        // {
        // l1=nums1[mid1-1];
        // r1=nums1[mid1];
        // ye isliy nhi karenge man lo left empty ,but right nhi
        // l1=min,r1=arr[mid1-1]


        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

        if (l1 > r2) {
            end = mid1 - 1;
        } else if (l2 > r1) {
            start = mid1 + 1;
        } else {
            if ((n1 + n2) % 2 == 0) {
                ans = (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                ans = max(l1, l2);
            }
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int>nums1={1,2,3};
    vector<int>nums2={5,6,7};
    double ans=findMedianSortedArrays(nums1,nums2);
    cout<<ans;

    return 0;
}