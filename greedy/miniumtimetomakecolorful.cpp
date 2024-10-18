#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minCost(string colors, vector<int> &neededTime)
{
    int prev = 0;
    int minimumTime = 0;
    for (int i = 1; i < colors.size(); i++)
    {
        if (colors[i] == colors[prev])
        {
            if (neededTime[i] > neededTime[prev])
            {
                minimumTime += neededTime[prev];
                prev = i;
            }
            else
            {
                minimumTime += neededTime[i];
            }
        }
        else
        {
            prev = i;
        }
        /* code */
    }
    return minimumTime;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string colors = "aba";
    vector<int> neededTime={1,2,3};
    int ans=minCost(colors, neededTime);
    cout<<ans;
    return 0;
}