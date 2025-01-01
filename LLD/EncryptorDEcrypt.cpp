#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// optimize think in reverse encypted se multiple word bnao,mtlb ek encrypted word ko decrypt kr rhe h toh multiple words
// wahi words ko encrypt krenge toh 1 word
class Encrypter
{
public:
    map<char, int> mp1;
    map<string,int>mp3;
    vector<char> keys;
    vector<string> values;
    vector<string> dictionary;
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary)
    {
        this->keys = keys;
        this->values = values;
        this->dictionary = dictionary;
        for (int i = 0; i < keys.size(); i++)
        {
            mp1[keys[i]] = i;
        }
        // brute force
        // for (int i = 0; i < values.size(); i++)
        // {
        //     mp2[values[i]].push_back(i);
        // }
        for (int i = 0; i < dictionary.size(); i++)
        {
            mp3[encrypt(dictionary[i])]++;
        }
    }

    string encrypt(string word1)
    {
        string ans = "";
        for (int i = 0; i < word1.length(); i++)
        {
            if (mp1.find(word1[i]) != mp1.end())
            {
                int ind = mp1[word1[i]];
                ans += values[ind];
            }
            else
            {
                ans += "";
            }

            /* code */
        }
        return ans;
    }
    // void f(int ind, string &word2, string current, int &count)
    // {
    //     int n = word2.length();
    //     if (ind>= n)
    //     {
    //         if (mp3.find(current) != mp3.end())
    //         {
    //             count++;
    //         }
    //         return;
    //     }
    //     string str = word2.substr(ind, 2);
    //     if (mp2.find(str) != mp2.end())
    //     {
    //         vector<int> v = mp2[str];
    //         for (auto i : v)
    //         {
    //             int index = i;
    //             current.push_back(keys[index]);
    //             f(ind + 2, word2, current, count);
    //             current.pop_back();
    //         }
    //     }
        
    // }

    // int decrypt(string word2)
    // {
    //     int count = 0;
    //     string current;
    //     f(0, word2, current,  count);
    //     return count;
    // }
    // int decrypt(string word2)
    // {
    //     int count = 0;
    //     string current;
    //     f(0, word2, current,  count);
    //     return count;
    // }//
     int decrypt(string word2)
    {
       return mp3[word2];
    }
    
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<char> keys = {'a', 'b', 'c', 'd'};
    vector<string> values = {"ei", "zf", "ei", "am"};
    vector<string> dictionary = {"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"};
    Encrypter obj(keys, values, dictionary);
    string ans=obj.encrypt("abcd");
    cout<<ans<<"\n";
    int ans2=obj.decrypt("eizfeiam");
    cout<<ans2<<"\n";

    return 0;
}