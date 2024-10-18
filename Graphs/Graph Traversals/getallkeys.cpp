#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// correct the code
class Custom
{
public:
   int i;
   int j;
   int steps;
   int key_status;
};
// i can take here vector
int bfs(vector<string> &grid, int i, int j, int count)
{
   int n = grid.size();
   int m = grid[0].size();
   // int val = pow(2, count)-1;
   // heap bufferflow
   int val = pow(2, count);
   vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(val, 0)));
   queue<Custom> q;
   Custom c;
   c.i = i;
   c.j = j;
   c.steps = 0;
   c.key_status = 0;
   visited[i][j][0] = 1;
   q.push(c);
   while (!q.empty())
   {
      Custom curr = q.front();
      q.pop();
      int x = curr.i;
      int y = curr.j;
      int moves = curr.steps;
      int key_status = curr.key_status;
      if(key_status ==val)
      {
         return moves;
      }
      int dx[4] = {-1, 1, 0, 0};
      int dy[4] = {0, 0, -1, 1};
      for (int t = 0; t < 4; t++)
      {
         int nx = x + dx[t];
         int ny = y + dy[t];
         if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#')
         {
            Custom child;
            child.i = nx;
            child.j = ny;
            child.steps = moves + 1;
            child.key_status = key_status;
            if (!visited[nx][ny][key_status])
            {
               if (islower(grid[nx][ny]))
               {
                  int shift = grid[nx][ny] - 'a';
                  child.key_status = child.key_status | (1 << shift);
                  visited[nx][ny][child.key_status] = true;
                  q.push(child);
               }
               else if (isupper(grid[nx][ny]))
               {
                  char t = tolower(grid[nx][ny]);
                  int set = t - 'a';
                  if (child.key_status & (1 << set))
                  {
                     visited[nx][ny][child.key_status] = true;
                     q.push(child);
                  }
               }
               else
               {
                  visited[nx][ny][child.key_status] = true;
                  q.push(child);
               }
            }
         }

         /* code */
      }
   }
   return -1;
}
int shortestPathAllKeys(vector<string> &grid)
{
   int count = 0;
   int n = grid.size();
   int m = grid[0].size();
   int start, end;

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == '@')
         {
            start = i;
            end = j;
         }
         else if (islower(grid[i][j]))
         {
            count++;
         }
         /* code */
      }

      /* code */
   }
   int ans = bfs(grid, start, end, count);
   return ans;
}
int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   vector<string> grid = {"@.a..","###.#","b.A.B"};
   int ans = shortestPathAllKeys(grid);
   cout << ans;

   return 0;
}