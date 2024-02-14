#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// return the least weight capacity  that wiil result
// all the packages on the conveyor belt being shipped within d days.
// brute force
// int shipWithinDays(vector<int> &weights, int days)
// {
//     // decide the range
//     // from 1 to sum
//     // from maxi to sum
//     int s = accumulate(weights.begin(), weights.end(), 0);
//     int maxi = *max_element(weights.begin(), weights.end());
//     int ans;
//     for (int i = maxi; i <= s; i++)
//     {
//         int sum = 0;
//         int d =1;
//         // d==0 nhi hoga ,agr hota toh iteration ke liy nhi run hoga
//         for (int j = 0; j < weights.size(); j++)
//         {
//             if (sum + weights[j] <=i)
//             {
//                 sum += weights[j];
//             }
//             else
//             {
//                 sum=0;
//                 sum += weights[j];
//                 d++;

//             }
//             /* code */
//         }
//         if (d <= days)
//         {
//             ans = i;
//             break;

//         }

//         /* code */
//     }
//     return ans;
// }
// optimised approach
int shipWithinDays(vector<int> &weights, int days)
{
    // decide the range
    // from 1 to sum
    // from maxi to sum
    int s = accumulate(weights.begin(), weights.end(), 0);
    int maxi = *max_element(weights.begin(), weights.end());
    long long ans = s;
    int start = maxi;
    int end = s;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // start + end >> 1
        long long sum = 0;
        long long d = 1;
        // d==0 nhi hoga ,agr hota toh iteration ke liy nhi run hoga
        for (int j = 0; j < weights.size(); j++)
        {
            if (sum + weights[j] <=mid)
            {
                sum += weights[j];
            }
            else
            {
                sum = 0;
                sum += weights[j];
                d++;
            }
            /* code */
        }
        if (d <= days)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return (int)ans;
}
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ans = shipWithinDays(weights, 5);
    cout << ans;

    return 0;
}