#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// row-wise
bool isValid(int n, int row, int col, vector<string> &str)
{
    // ---
    for (int m =row; m >= 0; m--)
    {
        if (str[m][col] == 'Q')
        {
            return false;
        }
        /* code */
    }
    int duprow = row;
    int dupcol = col;
    while (duprow >= 0 && dupcol >= 0)
    {
        if (str[duprow][dupcol] == 'Q')
        {
            return false;
        }
        duprow--;
        dupcol--;
    }

    duprow = row;
    dupcol = col;
    while (duprow>=0 && dupcol<n)
    {
        if (str[duprow][dupcol] == 'Q')
        {
            return false;
        }
        duprow--;
        dupcol++;
    }
    return true;
}
void f(int n, int row, vector<vector<string>> &output, vector<string> &str)
{
    if (row == n)
    {
        output.push_back(str);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isValid(n, row, col, str))
        {
            str[row][col] ='Q';
            f(n,row+1, output, str);
            str[row][col] ='.';
        }

        /* code */
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<string> str(n, string(n, '.'));
    vector<vector<string>> output;

    f(n, 0, output, str);
    return output;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<string>> output = solveNQueens(4);
    for (auto it : output)
    {
        vector<string> vec = it;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << "\n";
            /* code */
        }
        cout << "\n";
    }

    return 0;
}