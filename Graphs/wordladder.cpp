#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
int wordLadder(string begin, string end, vector<string> &dict) 
{
    // intialize q queue with pair
    queue<pair<string,int>>q;
    q.push({begin,1});
    // initialise a map for searching 
    unordered_map<string,bool>mp;
    for (int i = 0; i <dict.size(); i++)
    {
        mp[dict[i]]=true;
        /* code */
    }
    // erase the first element
    mp.erase(begin);
    int ts=-1;
    // transformation sequence length
    while(!q.empty())
    {
        string w=q.front().first;
        int level=q.front().second;
        q.pop();
        ts=max(level,ts);
        // replace each character of w and check it exist or not
        if(w==end)
        {
            return ts;
        }
        for (int i = 0; i <w.length(); i++)
        {
            // important step taki 
            // ex-hit ,i change krna ho tph pehla charcter h hi rhe
            char original=w[i];
            for (char ch ='a'; ch <='z'; ch++)
            {
                w[i]=ch;
                if(mp.find(w)!=mp.end())
                {
                    q.push({w,level+1});
                    // erase from map
                    mp.erase(w);
                }
                /* code */
            }
            w[i]=original;
            
            /* code */
        }
        
    }
    // edge case 

   

    return -1;
    

	// Write your code here
}



int main()
{
    vector<string>dict={"hot","dot","dog","lot","log","cog"};
    string begin="hit";
    string end="cog";
    int slen=wordLadder(begin,end,dict);
    cout<<slen;
    
return 0;
}