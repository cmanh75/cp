//problem "167-marisa"
//created in 18:29:46 - Thu 24/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int p[N], f[N];

int get_hash(int i, int j) {
    return (f[j] - 1ll * f[i - 1] * p[j - i + 1] % mod + mod) % mod;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = 1ll * p[i - 1] * 31 % mod;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = (1ll * f[i - 1] * 31 + s[i - 1] - 'a') % mod;
    }
    string ans;
    for (int i = 1; i <= n; i++) {
        int ok = true;
        for (int j = i; j <= n; j += i) {
            if (get_hash(j - i + 1, j) != get_hash(1, i)) {
                ok = false;
            }
        }
        if (n % i != 0 && get_hash((n / i) * i + 1, n) != get_hash(1, n % i)) {
            ok = false;
        }
        if (ok) {
            ans = s.substr(0, i);
            break;
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