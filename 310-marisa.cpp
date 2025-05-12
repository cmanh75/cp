//problem "310-marisa"
//created in 18:49:57 - Fri 10/01/2025
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, f[N][22];
const int mod = 1e9 + 7;

int get(int x, int y) {
    int o = log2(y - x + 1);
    return __gcd(f[x][o], f[y - (1 << o) + 1][o]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0];
    }
    for (int j = 1; j <= log2(n); j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k <= n) {
            int l = k + 1, r = n, ans = n + 1;
            int z = get(i, k);
            int gcd = z;
            while (l <= r) {
                int mid = (l + r) / 2;
                int u = get(i, mid);
                if (u != z) {
                    ans = mid;
                    gcd = u;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            res = (res + 1ll * (ans - k) * z) % mod;
            k = ans;
        }
    }
    cout << res;
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