// See the below part also***

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int power(int x, ll n, int mod) { // O(log n) = 64
    vector<int> xpw2(64, 0);
    xpw2[0] = x % mod; // x^(2^0)
    // Precomputing x raised to 2 to the power i  --> x^(2^i)
    for(int i = 1; i <= 63; i++) {
        xpw2[i] = 1LL * xpw2[i - 1] * xpw2[i - 1] % mod;
    }
    int ans = 1 % mod;
    for(int i = 0; i <= 63; i++) {
        if(n >> i & 1) {
            ans = 1LL * ans * xpw2[i] % mod;
        }
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


// Slightly modified version
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int power(int x, ll n, int mod) { // O(log n) = 64
    int cur = x % mod; // x^(2^0)   
    int ans = 1 % mod;
    for(int i = 0; i <= 63; i++) {
        if(n >> i & 1) {
            ans = 1LL * ans * cur % mod;
        }
        cur = 1LL * cur * cur % mod; 
        // This line makes even cleaner sense 
        // because power is always increasing by 2 
        // Say cur = x^4, so, it will be changed to (x^4 * x^4) = x^8 (2^2 --> 2^3)
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

