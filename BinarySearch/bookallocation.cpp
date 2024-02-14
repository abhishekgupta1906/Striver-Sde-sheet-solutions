#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// // 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.
// kisi particular ko kitna book mil skta h ,pagenumber+arr[i]<i

// brute force
// int findPages(vector<int> &arr, int n, int m)
// {
//     int maxi = *max_element(arr.begin(), arr.end());
//     int sum = accumulate(arr.begin(), arr.end(), 0);
//     if (m > n)
//     {
//         return -1;
//     }
//     int ans=-1;
//     for (int i = maxi; i <= sum; i++)
//     {
//         int students = 1;
//         int pageallocation = 0;
//         // check krp ek student ko kitna book mil skta h

//         for (int j = 0; j < arr.size(); j++)
//         {
//             if (pageallocation + arr[j] <= i)
//             {
//                 pageallocation = pageallocation + arr[j];
//             }
//             else
//             {
//                 pageallocation = arr[j];
//                 students++;
//             }
//             /* code */
//         }
//         if(students==m)
//         {
//            ans=i;
//            break;
//         }

//         /* code */
//     }
//     return ans;

//     // Write your code here.
// }
// optimize
int findPages(vector<int> &arr, int n, int m)
{
    int maxi = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (m > n)
    {
        return -1;
    }
    int ans = -1;
    int start = maxi;
    int end = sum;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int students = 1;

        int pageallocation = 0;
        // check krp ek student ko kitna book mil skta h

        for (int j = 0; j < arr.size(); j++)
        {
            if (pageallocation + arr[j] <=mid)
            {
                pageallocation = pageallocation + arr[j];
            }
            
            else
            {
                pageallocation = arr[j];
                students++;
            }
            /* code */
        }
        if(students>m)
        {
            // ans=mid;
            // ye nhi hoga
            start=mid+1;

        }
        else
        {
            end=mid-1;
        }
       
        /* code */
    }

    return start;

    // Write your code here.
}

int main()
{
    vector<int> pages = {25, 46, 28, 49, 24};
    int ans = findPages(pages, pages.size(), 4);
    cout << ans;

    return 0;
}