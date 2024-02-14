#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// problem h- k cows aise place krna,find minimum of maxium
// minimum tb milega jb stalls sorted
// 1-distance between any cows should be >=1
bool canposition(vector<int> &stalls, int dist, int cows)
{
    int k = 1;
    // no of cows
    int lastcowposition = 0;
    // at beginning o 1st and last is same
    // 1st cow placed at 0th index
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - stalls[lastcowposition] >= dist)
        {
            lastcowposition = i;
            k++;
        }
        if(k==cows)
        {
            return true; //
        }

    }
   
    return false;
}
// int aggressiveCows(vector<int> &stalls, int k)
// {
//     //    Write your code here.
//     sort(stalls.begin(), stalls.end());
//     int maxi = stalls[stalls.size() - 1];
//     int mini = stalls[0];
//     int range=maxi-mini;

//     for (int i = 1; i <= (maxi - mini); i++)
//     {
//         if(canposition(stalls,i,k)==false)
//         {
//             return i-1;
//         }
       
//     }
//     return range;
// }    
//optimise approach
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int maxi = stalls[stalls.size() - 1];
    int mini = stalls[0];
    int start=1;
    int end=maxi-mini;
    int ans=maxi-mini;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(canposition(stalls,mid,k)==false)
        {
            end=mid-1;

        }
        else
        {
            ans=mid;
            start=mid+1;
        }
    
    }
    return ans;

   
}   
int main()
{
    vector<int> stalls = {4,2,1,3,6};
    int ans = aggressiveCows(stalls,2);
    cout << ans;

    return 0;
}