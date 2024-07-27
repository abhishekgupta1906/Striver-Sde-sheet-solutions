#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// jb bhi subarray sum aye aur elements int he e-4<=a[i]<=e4 ,prefix[j]-prefix[i]=k
int subarraysDivByK(vector<int> &nums, int k)
{
   vector<int> prefix(nums.size());
   prefix[0] = nums[0];
   for (int i = 1; i < nums.size(); i++)
   {
      prefix[i] = prefix[i - 1] + nums[i];
      /* code */
   }
   // calculate the modulus
   for (int i = 0; i < prefix.size(); i++)
   {
      if (prefix[i] < 0)
      {
         prefix[i] = ((prefix[i] % k) + k) % k;
      }
      else
      {
         prefix[i] = (prefix[i]) % k;
      }

      /* code */
   }

   int ans = 0;
   map<int, int> mp;
   for (int j = 0; j < prefix.size(); j++)
   {
      if (prefix[j] == 0)
      {
         ans++;
      }
      ans += mp[prefix[j]];
      mp[prefix[j]]++;

      /* code */
   }
   return ans;
}
int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   vector<int> nums = {4, 5, 0, -3, -2, 1};
   int ans = subarraysDivByK(nums, 5);
   cout << ans; //
}