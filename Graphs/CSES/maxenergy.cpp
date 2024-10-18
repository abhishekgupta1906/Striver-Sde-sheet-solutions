#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        /* code */
    }
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arr1.push_back(arr[i]);
        }
        else
        {
            arr2.push_back(arr[i]);
        }

        /* code */
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    if (arr1.size() == 1 && arr2.size() == 1)
    {
        cout << arr1[0] + arr2[0];
    }
    else if (arr1.size() != 1 && arr2.size() <= 1)
    {
        cout << arr1[0] + arr1[1];
    }
    else if (arr1.size() <= 1 && arr2.size() != 1)
    {
        int n1 = arr2.size();
        cout << arr2[n1 - 1] + arr2[n1 - 2];
    }
    else
    {
        int n1 = arr2.size();

        int p1 = arr2[n1 - 1] * arr2[n1 - 2];
        int p2 = arr1[0] * arr1[1];
        if (p1 > p2)
        {
            cout << arr2[n1 - 1] + arr2[n1 - 2];
        }
        else
        {
            cout << arr1[0] + arr1[1];
        }
    }

    return 0;
}