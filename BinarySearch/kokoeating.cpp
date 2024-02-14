#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// problem-there are n piles ,each pile conatins pile[i] bananas
// find the minimum value of k ,so that koko can eat all the bananas
// k is speed of bananas per hr
// brute force approach
// in 1 hr koko can eat k bananas from the pile,she cannot move to another pile without finishing the first pile
// for pile[i]=7 ,k=2 ,time=7/2+1;
// brute force approach

// int minEatingSpeed(vector<int> &piles, int h)
// {
//     // find max of elements
//     int maxi = INT_MIN;
//     for (int i = 0; i < piles.size(); i++)
//     {
//         maxi = max(maxi, piles[i]);
//         /* code */
//     }
//     int ans = -1;

//     for (int i = 1; i <= maxi; i++)
//     {
//         // check for each how much it is taking to eat all piles
//         /* code */
//         int t = 0;
//         for (int j = 0; j < piles.size(); j++)
//         {
//             if (piles[j] % i == 0)
//             {
//                 t = t + (piles[j] / i);
//             }
//             else
//             {
//                 t = t + (piles[j] / i) + 1;
//             }

//             /* code */
//         }
//         if (t <= h)
//         {
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }
// optimised approach

int minEatingSpeed(vector<int> &piles, int h)
{
    // find max of elements
    int maxi = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        maxi = max(maxi, piles[i]);
        /* code */
    }
    // binary search
    long long ans = maxi;

    int start = 0;
    int end = maxi;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        long long t = 0;
        for (int j = 0; j < piles.size(); j++)
        {
            if (piles[j] % mid == 0)
            {
                t = t + (piles[j] / mid);
            }
            else
            {
                t = t + (piles[j] / mid) + 1;
            }
        }

        //

        if (t <= h)
        {
            ans = mid;
            end = mid - 1;
            // find minimum
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
    vector<int> v = {3, 6, 7, 11};
    int ans = minEatingSpeed(v, 8);
    cout << ans;

    return 0;
}