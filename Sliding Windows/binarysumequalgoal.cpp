#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// given a binary array find total number of arrays with sum equal goal
// Exactly(k)=At most(k)−At most(k−1)
int f(vector<int> &nums, int goal)
{
    // counting subarrays with sum<=goal
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = 0;
    while (j < nums.size())
    {
        sum = sum + nums[j];
        while (i <= j && sum > goal)
        {
            sum = sum - nums[i];
            i++;
        }
        ans = ans + (j - i + 1);
        j++;
    }
    return ans;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int sum1=f(nums,goal);
    // sum<=goal
    int sum2=0;
    if(goal>=1)
    {
        sum2=f(nums,goal-1);
    }

    // sum<=goal-1
    return (sum1-sum2);
}
int main()
{
    vector<int>nums={1,0,1,0,1};
    
    int ans=numSubarraysWithSum(nums,2);
    cout<<ans;

    return 0;
}