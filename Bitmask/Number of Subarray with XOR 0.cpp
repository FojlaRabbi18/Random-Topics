#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n + 1); 
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] ^ a[i];
    }
    map<int, int> mp; 
    mp[pre[0]]++; // Very important 
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += mp[pre[i]];
        mp[pre[i]]++;
    }
    cout << ans << '\n';

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
