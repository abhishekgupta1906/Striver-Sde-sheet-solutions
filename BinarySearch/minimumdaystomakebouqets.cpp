#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// minumum days to make m bouquets with adjacent flowers
//  range-mini to max
//  brute force
// int minDays(vector<int> &bloomDay, int m, int k)
// {
//     // edge case
//     if (m * k > bloomDay.size())
//     {
//         return -1;
//     }
//     int mini = *min_element(bloomDay.begin(), bloomDay.end());
//     int maxi = *max_element(bloomDay.begin(), bloomDay.end());
//     for (int day = mini; day <= maxi; day++)
//     {
//         int k1 = 0;
//         // for adjacency
//         int bouquet = 0;
//         for (int j = 0; j < bloomDay.size(); j++)
//         {
//             if (bloomDay[j] <= day)
//             {
//                 // flower bloom
//                 k1++;
//                 if (k1 == k)
//                 {
//                     // one bouquet
//                     bouquet++;
//                     k1 = 0;
//                 }
//             }
//             else
//             {
//                 k1 = 0;
//             }
//             /* code */
//         }
//         if (bouquet == m)
//         {
//             return day;
//         }

//         /* code */
//     }
//     return -1;
// }
// optimize
int minDays(vector<int> &bloomDay, int m, int k)
{
    // edge case
    // if (m * k > bloomDay.size())
    // {
    //     return -1;
    // }
      if (m> bloomDay.size()/k)
    {
        return -1;
    }
    // for leetcode
    int mini = *min_element(bloomDay.begin(), bloomDay.end());
    int maxi = *max_element(bloomDay.begin(), bloomDay.end());
    int start=mini;
    int end=maxi;
    while(start<=end)
    {
        int mid=(start+end)/2;
        int k1=0;
        int bouquet=0;
        for (int j = 0; j < bloomDay.size(); j++)
        {
            if (bloomDay[j] <=mid)
            {
                // flower bloom
                k1++;
                if (k1 == k)
                {
                    // one bouquet
                    bouquet++;
                    k1 = 0;
                }
            }
            else
            {
                k1 = 0;
            }
            /* code */
        }
        if(bouquet>=m)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
   return start;
   
}
int main()
{
    vector<int> bloomDay={1 ,2 ,1, 2 ,7 ,2, 2,3 ,1};
    // vector<int> bloomDay = {1, 10, 3, 4, 2};
    int ans = minDays(bloomDay,2,3);
    cout << ans;

    return 0;
}