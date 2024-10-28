//problem "165-marisa"
//created in 17:24:58 - Thu 24/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int p[N], f[N];

int get_hash(int l, int r) {
    return (f[r] - 1ll * f[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = 1ll * p[i - 1] * 31 % mod;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = (1ll * f[i - 1] * 31 + s[i - 1] - 'a') % mod;
    }
    int hash_t = 0;
    for (int i = 1; i <= t.size(); i++) {
        hash_t = (1ll * hash_t * 31 + t[i - 1] - 'a') % mod;
    }
    int ans = 0;
    for (int i = t.size(); i <= n; i++) {
        if (get_hash(i - t.size() + 1, i) == hash_t) {
            ans++;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test = 1;
    while (test--) {
        solve();
    }
}