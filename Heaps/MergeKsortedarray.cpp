#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, pair<int, int>>
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int>ans;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i <K; i++)
    {
        pq.push({arr[i][0],{i,0}});
        /* code */
    }
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        ans.push_back(it.first);
        int i=it.second.first;
        int j=it.second.second;
        if(j+1<K)
        {
            pq.push({arr[i][j+1],{i,j+1}});
        }
    }
    return ans;
    
    // code here
}
int main()
{
    vector<vector<int>>nums={{1,2,3},{4,5,6},{7,8,9}};
    vector<int>ans=mergeKArrays(nums,3);
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
        /* code */
    }
    

    return 0;
}