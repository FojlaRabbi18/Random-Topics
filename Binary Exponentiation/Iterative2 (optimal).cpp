#include<bits/stdc++.h>
using namespace std;
#define ll long long

int power(int x, ll n, int mod) { // O(log n) = 64
    x = x % mod; // x^(2^0)   
    int ans = 1 % mod;
    while(n > 0) {
        if(n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod; 
        n = n >> 1; // Another way of traversal 
    }
    return ans;
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << power(1e8 + 9, 1e18, 1e9 + 7);
    return 0;
}
// 908727740
