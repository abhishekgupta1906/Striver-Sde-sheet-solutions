#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
// problem h alien dictionary diya hua h,uska order find out karo
// two consecutive strings ko lo aur pehla unmatching jo charaters aye unke for ex-'t'->'f
// using topo sort kahn algorithm
// k ka mtlb h first k alphabets of stanadrd dictionary
// toh alien dictionary me inka order kya hoga
vector<int> toposort(int n, vector<int>adj[])
{
    
    vector<int> indegree1(n, 0);
    for (int i =0; i < n ; i++)
    {
        for (auto it:adj[i])
        {
            indegree1[it]++;
            /* code */
        }

        /* code */
    }
    // push in the queue
    queue<int> q;
    vector<int>ans;

    for (int i =0; i < n; i++)
    {
        if (indegree1[i] == 0)
        {
            q.push(i);
        }
        /* code */
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it:adj[node])
        {
            indegree1[it]--;
            if (indegree1[it] == 0)
            {
                q.push(it);
            }
            /* code */
        }
    }
    return ans;
   

    // Write your code here.
}
string getAlienLanguage(vector<string> &dictionary, int k)
{
    // first k order
    vector<int>adj[k];
    for (int i = 0; i <dictionary.size()-1; i++)
    {
        string s1=dictionary[i];
        string s2=dictionary[i+1];
        int len=min(s1.length(),s2.length());
        for (int j = 0; j <len; j++)
        {
            if(s1[j]!=s2[j])
            {
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                // only first unmatched characters
                break;
                // for indexing purposes
                // integer vertices
            }
            /* code */
        }
        
        /* code */
    }
    vector<int>ans=toposort(k,adj);
    string s="";
   
    for (auto it:ans)
    {
        s=s+char(it+'a');
        /* code */
    }
    return s;
    
    
    // Write your code here.
}
int main()
{
    // char a='a';
    // char b='b';
    // int c='t'-'a';
    // char d=c+'a';
    vector<string>dict={"caa", "aaa", "aab"};
    string s=getAlienLanguage(dict,3);
    cout<<s;


  
   
   
    // cout<<d;

return 0;
}