#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, pair<int, int>>
// refer to k pairwith smallestsum
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int n = nums1.size();
    int m = nums2.size();
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());

    priority_queue<pii> pq;
    pq.push({nums1[0] + nums2[0], {0, 0}});
    set<pair<int, int>> st;
    st.insert({0, 0});
    int K = c;
    vector<int> ans;
    while (K != 0)
    {
        auto it = pq.top();
        pq.pop();
        int i = it.second.first;
        int j = it.second.second;
        ans.push_back(it.first);
        // check diagonals
        if (i + 1 < n && j < m && st.find({i + 1, j}) == st.end())
        {
            pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            st.insert({i + 1, j});
        }
        if (i < n && j + 1 < m && st.find({i, j + 1}) == st.end())
        {
            pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            st.insert({i, j + 1});
        }
        K--;
    }
    return ans;
}

int main()
{

    return 0;
}