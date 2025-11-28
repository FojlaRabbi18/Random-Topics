#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout << #x << ": " << x << '\n'

void solve() { 
    int n, k; 
    cin >> n >> k;
    
    vector<int> a(n);
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    bool flag = true;
    for(auto [x, y]: freq) {
        if(y % k != 0) flag = false;
    }
    ll ans = 0;
    if(flag) {
        for(int i = 0; i < n; i++) {
            map<int, int> temp;
            for(int j = i; j < n; j++) {
                temp[a[j]]++;
                if(temp[a[j]] <= (freq[a[j]] / k)) ans++;
                else break;
            }
        }
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
