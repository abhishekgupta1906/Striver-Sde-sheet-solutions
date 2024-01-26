#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>&matrix, pair<int, int> src, pair<int, int> dest)
{
   if (src.first == dest.first && src.second == dest.second)
{
    return 0;
}
queue<pair<int, pair<int, int>>> q;
int n = matrix.size();
int m = matrix[0].size();
vector<vector<int>> dist(n, vector<int>(m, 1e9));
dist[src.first][src.second] = 0;
q.push({0, {src.first, src.second}});
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
while (!q.empty())
{
    auto it = q.front();
    q.pop();
    int dis = it.first;
    int r = it.second.first;
    int c = it.second.second;
    for (int i = 0; i < 4; i++)
    {
        int newr = r + dr[i];
        int newc = c + dc[i];
        if (newr >= 0 && newr < n && newc >= 0 && newc < m && matrix[newr][newc] == 1 && dis + 1 < dist[newr][newc])
        {
            dist[newr][newc] = 1 + dis;
            if (newr == dest.first && newc == dest.second)
            {
                return dis + 1;
            }
            q.push({dis + 1, {newr, newc}});
        }
    }
}
return -1;
    
    
    // Write your code here
}
int main()
{
    vector<vector<int>>matrix={{1,1,1,1},{0,1,1,0},{0,0,1,1}};
    pair<int, int> src={0,0};
    pair<int, int> dest={2,3};

    int ans=shortestPathBinaryMatrix(matrix,src,dest);
    cout<<ans;
    
return 0;
}