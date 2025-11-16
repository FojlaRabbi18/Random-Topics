// See the below part also***

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int binpow(int a, ll n, int m) { // O(log n) = 63
    vector<int> apw2(63); // 63 is enough, long long --> total 63 bits (as highest value is 2^63 - 1)
    apw2[0] = a % m; // a^(2^0)
    // Precomputing a raised to 2 to the power i  --> a^(2^i)
    for(int i = 1; i <= 62; i++) {
        apw2[i] = 1LL * apw2[i - 1] * apw2[i - 1] % m;
    }
    ll res = 1 % m;
    for(int i = 0; i <= 62; i++) {
        if(n >> i & 1) {
            res = res * apw2[i] % m;
        }
    }
    return res;
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << binpow(1e8 + 9, 1e18, 1e9 + 7);
    return 0;
}
// 908727740


// Slightly modified version
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int binpow(int a, ll n, int m) { // O(log n) = 63
    ll cur = a % m; // a^(2^0)   
    ll res = 1 % m;
    for(int i = 0; i <= 62; i++) {
        if(n >> i & 1) {
            res = res * cur % m;
        }
        cur = cur * cur % m; 
        // This line makes even cleaner sense 
        // because power is always getting doubled (power of 2 is increasing by 1) 
        // Say cur = a^4, so, it will be changed to (a^4 * a^4) = a^8 (2^2 --> 2^3)
    }
    return res;
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << binpow(1e8 + 9, 1e18, 1e9 + 7);
    return 0;
}
// 908727740
