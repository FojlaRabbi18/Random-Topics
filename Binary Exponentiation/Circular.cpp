// Only effective when mod value is small

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void power(int x, int n, int mod) {
    int cur = 1 % mod;
    vector<int> v;
    v.push_back(1); // Pos 0, value 1, x^0
    vector<bool> vis(mod, false);
    int start = 0;
    while(true) {
        cur = cur * x % mod;
        if(!vis[cur]) {
            vis[cur] = true;
            v.push_back(cur);
        }
        else {
            start = find(v.begin(), v.end(), cur) - v.begin();
            break;
        }
       
    }
    int cycle_len = v.size() - start;
    for(auto i: v) cout << i << " ";
    cout << '\n';
    cout << "start = " << start << '\n';
    if(n < start) cout << v[n];
    else {
        // Say n = 100, but I actually need to traverse 97 positions 
        // inside the infinite cycle (as start = 3)
        n -= start;
        cout << v[start + n % cycle_len] << '\n';        
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    power(2, 9, 40);
    return 0;
}
/*
1 2 4 8 16 32 24 
start = 3
32
*/
