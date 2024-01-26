#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
// find all the shortest tranistions from start to finish
/*
pool={cot,cog,dog,dot,dat,dag,dig}
backtrack step
              dog
             /
            dot
            /  \
           dat cot
           /     \
         cat     cat
         sequence se pop back kra to backtrack

*/
string begin1;
void backtracking(string word, vector<string> &seq, vector<vector<string>> &ans, unordered_map<string, int> &mp)
{
    // base case
    if (word == begin1)
    {
        reverse(seq.begin(), seq.end());
        // to get the sequence in original manner
        ans.push_back(seq);
        // to get the sequence from where it ends
        reverse(seq.begin(), seq.end());
        return;
    }
    int steps = mp[word];
    for (int i = 0; i < word.size(); i++)
    {
        char real = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if(mp.find(word)!=mp.end() && mp[word]==steps-1)
            {
                seq.push_back(word);
                backtracking(word,seq,ans,mp);
                seq.pop_back();
                // check upper
            }
          
            /* code */
        }
        word[i] = real;

        /* code */
    }
}
vector<vector<string>> shortestTransitionPaths(string start, string finish, vector<string> &wordPool)
{
    unordered_set<string> s(wordPool.begin(), wordPool.end());
    unordered_map<string, int> mp;
    queue<string> q;
    begin1 = start;
    mp[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        string word = q.front();
        int steps =mp[word];
        // min steps to reach word from start
        q.pop();
        if (word == finish)
        {
            break;
        }
        for (int i = 0; i < word.size(); i++)
        {
            char real = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    // erase word from set
                    mp[word] = steps + 1;
                    q.push(word);
                
                }
                /* code */
            }
            word[i] = real;

            /* code */
        }
    }
    // search end word from last
    vector<vector<string>> ans;
    if (mp.find(finish) != mp.end())
    {
        vector<string> seq;
        seq.push_back(finish);
        backtracking(finish, seq, ans, mp);
    }
    return ans;

    // Write your code here.
}
int main()
{
    vector<string>pool={"cot","cog","dog","dot","dat","dag","dig"};
    vector<vector<string>>ans=shortestTransitionPaths("cat","dog",pool);
    for (int i = 0; i <ans.size(); i++)
    {
        for (int j = 0; j <ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
            /* code */
        }
        cout<<endl;
        
        /* code */
    }
    



    return 0;
}