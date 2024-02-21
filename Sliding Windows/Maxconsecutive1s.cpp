#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// find the max consecutive ones by flipping atmost k zeroes
// soln-iska mtlb max consecutive ones jo tha usme atmost k zeroes hoga
// sliding window
int longestOnes(vector<int> &nums, int k)
{
    int i=0;
    int j=0;
    int cntk=0;
    int ans=INT_MIN;
    while(j<nums.size())
    {
        if(nums[j]==0)
        {
            cntk++;
        }
        while(i<j && cntk>k)
        {
            if(nums[i]==0)
            {
                cntk--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;

}
int main()
{
    vector<int>nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int ans=longestOnes(nums,3);
    cout<<ans;

    return 0;
}