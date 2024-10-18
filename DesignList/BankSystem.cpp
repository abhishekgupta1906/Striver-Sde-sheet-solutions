#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
class Bank
{

    int n;

    vector<long long>bal;
    // 1 based
public:
    Bank(vector<long long> &balance)
    {
        n = balance.size();
        bal.resize(n+1);
        for (int i = 1; i < n + 1; i++)
        {
            bal[i] = balance[i - 1];
            /* code */
        }
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 > n || account1 < 1 || account2 > n || account2 < 1 || bal[account1] < money)
            return false;
        bal[account1] -= money;
        bal[account2] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account > n || account < 1)
            return false;
        bal[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account > n || account < 1 || bal[account] < money)
            return false;
        bal[account] -= money;
        return true;
    }
};

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank *obj = new Bank(balance);
    bool b = obj->transfer(1, 2, 11);
    cout << b;
    delete obj;
    return 0;
}