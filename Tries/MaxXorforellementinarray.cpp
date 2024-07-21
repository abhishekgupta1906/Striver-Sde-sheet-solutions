#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    map<int, TrieNode *> child;

    TrieNode() {}
    ~TrieNode()
    {
        for (auto &pair : child)
        {
            delete pair.second;
        }
    }
};

// Trie class
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode;
    }
    ~Trie()
    {
        delete root;
    }

    void insert(int num, int bitLength)
    {
        TrieNode *curr = root;
        for (int i = bitLength - 1; i >= 0; i--)
        {
            int bit = (num & (1 << i)) ? 1 : 0;
            if (curr->child[bit] == NULL)
            {
                curr->child[bit] = new TrieNode;
            }
            curr = curr->child[bit];
        }
    }

    int max_XOR(int num, int bitLength)
    {
        TrieNode *curr = root;
        int ans = 0;
        for (int i = bitLength - 1; i >= 0; i--)
        {
            int bit = (num & (1 << i)) ? 1 : 0;
            if (bit == 0)
            {
                if (curr->child[1] != NULL)
                {
                    ans += 1 << i;
                    curr = curr->child[1];
                }
                else
                {
                    curr = curr->child[0];
                }
            }
            else
            {
                if (curr->child[0] != NULL)
                {
                    ans += 1 << i;
                    curr = curr->child[0];
                }
                else
                {
                    curr = curr->child[1];
                }
            }
        }
        return ans;
    }
};

vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
{
   
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> myqueries;
    long long maxi=0;
    for (int i = 0; i < queries.size(); i++)
    {
        int x = queries[i][0];
        int m = queries[i][1];
        maxi=max(maxi,(long long)x);
        myqueries.push_back({m, {x, i}});
    }
    sort(myqueries.begin(), myqueries.end());
   
    long long maxNum = *max_element(nums.begin(), nums.end());
    // max num in the array
    maxNum = max(maxNum,maxi);
    // max num in the
    long long bitLength = ceil(log2(maxNum + 1));
    
    Trie t;
    int i = 0;
    vector<int> result(queries.size(), -1); 
    for (auto it : myqueries)
    {
        while (i < nums.size() && nums[i] <= it.first)
        {
            t.insert(nums[i], bitLength);
            i++;
        }
        if (i != 0)
        {
            result[it.second.second] = t.max_XOR(it.second.first, bitLength);
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
    vector<int> result = maximizeXor(nums, queries);
    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}
