#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; 
    cin >> n;

    vector<ll> a(n);
    int even_cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) even_cnt++;
    }
    if(even_cnt == n || even_cnt == 0) cout << "4\n";
    else cout << "2\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
