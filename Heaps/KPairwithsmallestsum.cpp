#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, pair<int, int>>
// dekho question actual main return k smallest sum
// brute force hoga sara combination ka sum store kr lo aur sort krdo
// nums1 = [1,7,11], nums2 = [2,4,6]
// agar k smallest chaiye ,toh i->nums1  j->nums2
// ek toh sure h dona arrays ka pehla element 1 6
// dusra kya 7 4 hoga nhi ,(i+1,j) and (i,j+1) diagonals but why
// Reason
// man lo nums1[i-1]+nums[j]=a
// nums1[i]+nums[j-1]=b
// nums1[i-1]+nums[j-1]=c
// dono arrays sorted h,  a,b<=c (equality when nums1[i]==nums1[i-1]) similarly for j

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    // min heap priority queue
    int n = nums1.size();
    int m=nums2.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({nums1[0] + nums2[0], {0, 0}});
    set<pair<int, int>> st;
    st.insert({0, 0});
    int K = k;
    vector<vector<int>> ans;
    while (K != 0)
    {
        auto it = pq.top();
        pq.pop();
        int i = it.second.first;
        int j = it.second.second;
         ans.push_back({nums1[i], nums2[j]});
        // check diagonals
        if (i+1< n && j<m && st.find({i + 1, j}) == st.end())
        {
            pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            st.insert({i + 1, j});
        }
        if (i < n && j+1 <m && st.find({i, j + 1}) == st.end())
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
    vector<int>nums1={1,7,11};
    vector<int>nums2={2,4,6};
    vector<vector<int>>ans=kSmallestPairs(nums1,nums2,3);
    for (int i = 0; i <ans.size(); i++)
    {
        for (int j = 0; j <ans[i].size(); j++)
        {
            cout << ans[i][j]<<" ";
            /* code */
        }
        cout<<" ";
        
        /* code */
    }
    

    return 0;
}