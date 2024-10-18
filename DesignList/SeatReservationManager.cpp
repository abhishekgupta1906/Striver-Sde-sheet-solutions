#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
class SeatManager {
    set<int>st;
public:
    SeatManager(int n) {
        for (int i =1; i <=n; i++)
        {
            st.insert(i);
            /* code */
        }
        
    }
    
    int reserve() {
       
        auto it = st.begin();
        int val=*(it);
        st.erase(it);
        return val;
        
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
        
    }
};
int main()
{
    
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   return 0;
}