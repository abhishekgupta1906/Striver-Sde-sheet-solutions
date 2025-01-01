#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(vector<int>&nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int ind=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
    if(ind>=n){
        return -1;
        // aur elements nhi le skte
    }
    int count=0;
    int sum=0;
    for (int i =ind; i <n; i++)
    {
        count++;
        sum+=nums[i];
        /* code */
    }
    for (int i =ind-1; i>=0; i--)
    {
        sum+=nums[i];
        if(sum>=0){
            count++;
        }
        else{
            break;
        }
        /* code */
    }
    return count;
    



}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={1,-20,3,-2};
    int ans=f(nums);
    cout<<ans;
    return 0;
}