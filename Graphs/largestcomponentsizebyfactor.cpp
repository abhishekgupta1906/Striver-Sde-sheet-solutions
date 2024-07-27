#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Dsu
{
public:
    vector<int> parent;
    vector<int> s;
    Dsu(int n)
    {
        parent.resize(n);
        s.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            s[i] = 1;
            /* code */
        }
    }
    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return findParent(parent[node]);
    }
    void unionbySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;
        if (s[pu] < s[pv])
        {
            parent[pu] = pv;
            s[pv] += s[pu];
        }
        else
        {
            parent[pv] = pu;
            s[pu] += s[pv];
        }
    }
};

int largestComponentSize(vector<int> &nums)
{
    int n = nums.size();
    Dsu ds(n);
    int maxi = *max_element(nums.begin(), nums.end());
    vector<bool> visited(maxi + 1, false);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = i;
        /* code */
    }

    // sieve

    for (int i = 2; i <= maxi; i++)
    {
        if (visited[i])
        {
            continue;
        }
        vector<int> divisors;
        for (int j = i; j <= maxi; j += i)
        {
            if (mp.find(j) != mp.end())
            {
                divisors.push_back(mp[j]);
                visited[j] = true;
            }
            /* code */
        }
        if (divisors.size() >= 2)
        {
            for (int m = 1; m < divisors.size(); m++)
            {
                ds.unionbySize(divisors[0], divisors[m]);
                /* code */
            }
        }

        /* code */
    }

    vector<int> arr = ds.s;
    maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
        /* code */
    }
    return maxi;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {2, 3, 6, 7, 4, 12, 21, 39};
    int ans = largestComponentSize(nums);
    cout << ans;
    return 0;
}