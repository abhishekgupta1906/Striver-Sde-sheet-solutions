#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;
    // problem clear h  num insert hone ke baad,overall elements sorted hona chaiye
class MedianFinder
{
public:
    pbds med;
    int key;
    MedianFinder()
    {
        key = 0;
    }

    void addNum(int num)
    {
        med.insert({num, key});
        key++;
    }

    double findMedian()
    {
        if (med.size() % 2 == 0)
        {
            int n = med.size();
            int mid = n/2;
            auto it = *med.find_by_order(mid-1);
            auto it2 = *med.find_by_order(mid);
            double ans = (it.first + it2.first) * 1.0 / 2;
            return ans;
        }
        else
        {
            int n = med.size();
            int mid = n - 1 / 2;
            auto it = *med.find_by_order(mid);
            double ans = (it.first) * 1.0;
            return ans;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pbds A;
    A.insert({1, 2});
    auto it = *A.find_by_order(0);
    cout << it.second;

    return 0;
}