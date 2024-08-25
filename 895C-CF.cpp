//problem "895C-CF"
//created in 17:18:37 - Sat 24/08/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e5;
const int mod = 1e9 + 7;
int n, a[N], p[N], d[N], m = 0, dp[2][2050], e[N];
int b[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
long long g[N], f[N];

long long power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    long long t = power(x, y / 2);
    if (y & 1) {
        return t * t % mod * x % mod;
    }
    return t * t % mod;
}

long long c(int x, int y) {
    return g[y] * f[x] % mod * f[y - x] % mod;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= 10; i++) {
        p[b[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int u = 0;
        for (int j = 2; j <= 35; j++) {
            int cnt = 0;
            while (a[i] % j == 0) {
                a[i] /= j;
                cnt++;
            }
            if (cnt & 1) {
                u |= (1 << p[j]);
            }
        }
        if (a[i] - 1) {
            d[a[i]]++;
        }
        else {
            e[++m] = u;
        }
    }
    g[0] = 1;
    for (int i = 1; i <= M; i++) {
        g[i] = g[i - 1] * i % mod;
    }
    f[M] = power(g[M], mod - 2);
    for (int i = M - 1; i >= 0; i--) {
        f[i] = f[i + 1] * (i + 1) % mod;
    }
    long long ans = 1;
    for (int i = 35; i <= 70; i++) {
        if (d[i]) {
            long long res = 0;
            for (int j = 0; j <= d[i]; j += 2) {
                res = (res + c(j, d[i])) % mod;   
            }
            ans = ans * res % mod;
        }
    }
    dp[1][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (1 << 11); j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
        for (int j = 0; j < (1 << 11); j++) {
            dp[1][j] = (dp[1][j] + dp[0][j]) % mod;
            dp[1][j ^ e[i]] = (dp[1][j ^ e[i]] + dp[0][j]) % mod;
        }
    }
    cout << (1ll * dp[1][0] * ans - 1) % mod;
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