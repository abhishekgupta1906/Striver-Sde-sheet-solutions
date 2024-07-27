#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// this problem is in gfg ,mainly high=mid in binary search on floating points in order to maintain precisions
bool check(vector<int> &stations, int k, double mid)
{
   int points = 0;
   for (int i = 1; i < stations.size(); i++)
   {
      double val = stations[i] - stations[i - 1];
      points +=ceil(val/mid)- 1;
      /* code */
   }
   if (points <= k)
   {
      return true;
   }
   return false;
}
double findSmallestMaxDist(vector<int> &stations, int k)
{
   int n = stations.size();
   double ans = 0;
   double low = 0.0;
   double high = stations[n - 1] - stations[0];

   while (high-low>1e-6)
   {
      double mid = low + (high - low)/2.0;
      if (check(stations, k, mid))
      {
         ans = mid;
         high = mid;
      }
      else
      {
         low = mid;
      }
   }
   return ans;

   
}
int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   double ans = findSmallestMaxDist(stations, 9);
   cout << ans;

   return 0;
}