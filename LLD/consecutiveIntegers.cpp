#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// brute force
// class DataStream
// {
// public:
//     stack<int> st;
//     int value;

//     int K;
//     DataStream(int value, int k) {
//         this->value = value;

//         this->K = k;
//     }
//     // o(k)
//     bool consec(int num) {
//         st.push(num);
//         if (st.size() >= K) {
//             vector<int> nums;
//             int size = 0;
//             bool found = true;
//             while (size < K) {
//                 int element = st.top();
//                 if (element !=value) {
//                     found = false;
//                 }
//                 nums.push_back(element);

//                 st.pop();
//                 size++;
//             }
//             reverse(nums.begin(), nums.end());
//             for (int i = 0; i < nums.size(); i++) {
//                 st.push(nums[i]);
//                 /* code */
//             }

//             return found;
//         }
//         return false;
//     }
// };
class DataStream
{
public:
    
    int value;
    int last_value;
    // last_value not equal to value and its size
    int last_size;
    int size;

    int K;
    DataStream(int value, int k)
    {
        this->value = value;
        this->K = k;
        last_value = -1;
        last_size = 0;
        size = 0;
    }

    bool consec(int num)
    {
        
        size++;
        if(num!=value){
            last_value=num;
            last_size=size;
        }
        if(size<K){
            return false;
        }
        if(size-last_size>=K){
            return true;
        }
        return false;

    }

    // o(k)
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    DataStream obj(4, 3);
    cout << obj.consec(4) << "\n";
    cout << obj.consec(4) << "\n";
    cout << obj.consec(4) << "\n";
    cout << obj.consec(3) << "\n";

    return 0;
}