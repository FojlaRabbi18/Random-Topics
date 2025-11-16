#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 5, m = 1e9 + 7;
int binpow(ll a, ll n, int m) { // O(log n)
    a = a % m;   
    ll res = 1 % m;
    while(n > 0) {
        if(n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
  
}
// m must be Prime and cannot divide a 
// If any fact is divisible by m, then WA
// N = 1e6 + 5 is safer as m = 1e9 + 7 (fact % m won't be 0)
int inverse(int a, int m) {
    return binpow(a, m - 2, m);
}

int fact[N], invfact[N];
void pre_fact() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % m;
    }
    // for(int i = 0; i < N; i++) { // O(N * log N)
    //     invfact[i] = inverse(fact[i], m);
    // }
    invfact[N - 1] = inverse(fact[N - 1], m) % m;
    for(int i = N - 2; i >= 0; i--) {
        invfact[i] = 1LL * invfact[i + 1] * (i + 1) % m;
    }
}

int nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return 1LL * fact[n] * invfact[n - r] % m * invfact[r] % m;
}
int nPr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return 1LL * fact[n] * invfact[n - r] % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre_fact();
    cout << nCr(5, 3);  
    return 0;
}
