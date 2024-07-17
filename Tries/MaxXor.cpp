#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// class TrieNode {
// public:
//     TrieNode* child[2];

//     TrieNode() {
//         child[0] = NULL;
//         child[1] = NULL;
//     }
//     ~TrieNode() {
//         delete child[0];
//         delete child[1];
//     }
// };
class TrieNode {
public:
    map<int, TrieNode*> child;

    TrieNode() {}
    ~TrieNode() {
        for (auto& pair : child) {
            delete pair.second;
        }
    }
};

// Trie class
class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode;
    }
    ~Trie() {
        delete root;
    }

    void insert(TrieNode* root, int& num, int& bitLength) {
        TrieNode* curr = root;
        for (int i = bitLength - 1; i >= 0; i--) {
            int bit = (num & (1 << i)) ? 1 : 0;
            if (curr->child[bit] == NULL) {
                curr->child[bit] = new TrieNode;
            }
            curr = curr->child[bit];
        }
    }

    void insert(int& num, int& bitLength) {
        insert(root, num, bitLength);
    }

    int max_XOR(TrieNode* root, int& num, int& bitLength) {
        TrieNode* curr = root;
        int ans = 0;
        for (int i = bitLength - 1; i >= 0; i--) {
            int bit = (num & (1 << i)) ? 1 : 0;
            if (bit == 0) {
                if (curr->child[1] != NULL) {
                    ans += 1 << i;
                    curr = curr->child[1];
                } else {
                    curr = curr->child[0];
                }
            } else {
                if (curr->child[0] != NULL) {
                    ans += 1 << i;
                    curr = curr->child[0];
                } else {
                    curr = curr->child[1];
                }
            }
        }
        return ans;
    }

    int max_XOR(int& num, int& bitLength) {
        return max_XOR(root, num, bitLength);
    }
};


int findMaximumXOR(vector<int>& nums) {
    int maxNum = *max_element(nums.begin(), nums.end());
    int bitLength = ceil(log2(maxNum + 1));
    Trie t;

    int n = nums.size();
    int max_xor = 0;
    t.insert(nums[n - 1], bitLength);
    for (int i = n - 2; i >= 0; i--) {
        max_xor = max(max_xor, t.max_XOR(nums[i], bitLength));
        t.insert(nums[i], bitLength);
    }
    return max_xor;
}

// Main function to test the code
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR: " << findMaximumXOR(nums) << endl;

    return 0;
}




