#include<iostream>
#include<string>
#include<vector>
using namespace std;
// adjacency list representation
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adjlist[n];
    cout<<"start"<<endl;
    // nodes 0 based
    for (int i = 0; i <m; i++)
    {
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        /* code */
    }
    cout<<"finished";
    // kisi node ke neighbours pr taverse krne ke liy
    for(auto it:adjlist[n])
    {
        cout<<it<<endl;

    }
    
    
    

    
return 0;
}