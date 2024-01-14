#include <iostream>
#include <string>
#include <vector>
using namespace std;
// har color hona chaiye nodes and their adj nodes should be diffrently coloured
// you can do any traversal
// we will follow dfs
// two color 1,2  -1 for colorless Nodes
void dfs(vector<vector<int>> &graph, int src, vector<int> &color)
{
    int col = color[src];

    for (int i = 0; i < graph[src].size(); i++)
    {
        int adjnode = graph[src][i];
        if (color[adjnode] == -1)
        {
            if (col == 1)
            {
                color[adjnode] = col + 1;
            }
            else
            {
                color[adjnode] = col - 1;
            }
            dfs(graph, adjnode, color);
        }
    }
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);

    // -1 means node is not coloured

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            // make it source and define color
            color[i] = 1;
            dfs(graph, i, color);
        }
        /* code */
    }
    for (int i = 0; i < n; i++)
    {
        int col = color[i];
        for (int j = 0; j < graph[i].size(); j++)
        {
            int adjnode = graph[i][j];
            if (col == color[adjnode])
            {
                return false;
            }
            /* code */
        }

        /* code */
    }
    return true;
}

int main()
{
   vector<vector<int>>graph={{1,3},{0,2},{1,3},{0,2}};
   bool a=isBipartite(graph);
   cout<<a;

    return 0;
}