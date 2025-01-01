#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int minimumObstacles(vector<vector<int>> &grid)
{
   priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
   int m=grid.size();
   int n=grid[0].size();
   vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
   int dx[4]={-1,1,0,0};
   int dy[4]={0,0,-1,1};
//    obstacle priority h ,dist[i][j]-min obstacles to reach i,j
  pq.push({0,{0,0}});
  int mini=0;
  while(!pq.empty()){
    auto it=pq.top();
    int stops=it.first;
    int x=it.second.first;
    int y=it.second.second;
    pq.pop();
    for (int i = 0; i <4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<m && ny>=0 && ny<n){
            // min obstacles to reach nx ny se kuch km mil rha h kya
            int min_stops=stops+grid[nx][ny];
            if(min_stops<dist[nx][ny]){
               dist[nx][ny]=min_stops;
               pq.push({min_stops,{nx,ny}});
            }

            
        }
        /* code */
    }
    
  }
  return dist[m-1][n-1];


}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}