#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// find the no of sub arrays containing exactly k distinct elements
// exactly(k)=atmost(k)-atmost(k-1);
    int f(vector<int> &nums, int k)
{
    int i=0;
    int j=0;
    int ans=0;
    unordered_map<int,int>freq;
    while(j<nums.size())
    {
        freq[nums[j]]++;
        while(i<=j && freq.size()>k)
        {
            freq[nums[i]]--;
            if(freq[nums[i]]==0)
            {
                freq.erase(nums[i]);
            }
            i++;
        }
        ans=ans+(j-i+1);
        j++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int atmostk=f(nums,k);
    int atmostk1=0;
    if(k>=1)
    {
        atmostk1=f(nums,k-1);
    }
   
    // atmost k-1
    return (atmostk-atmostk1);
}
int main()
{
    vector<int>nums={1,2,1,1,3};
    int ans=subarraysWithKDistinct(nums,2);
    cout<<ans;

    return 0;
}