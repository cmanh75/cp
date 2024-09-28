//problem "53E-CF"
//created in 12:15:11 - Mon 16/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, m, k, u[N], v[N];
long long dp[N][N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
        int z = (1 << (u[i] - 1)) | (1 << (v[i] - 1));
        dp[z][z] = 2;
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j <= i; j++) {
            if ((i & j) != j) {
                continue;
            }
            dp[i][j] /= __builtin_popcount(j);
            for (int h = 1; h <= m; h++) {
                if ((i >> (u[h] - 1) & 1) && (i >> (v[h] - 1) & 1)) {
                    continue;
                }
                if (!((i >> (u[h] - 1) & 1) || (i >> (v[h] - 1) & 1))) {
                    continue;
                }
                int newi = i | (1 << (u[h] - 1)) | (1 << (v[h] - 1));
                int newj = j;
                if ((!(i >> (u[h] - 1) & 1)) || (j >> (u[h] - 1) & 1)) {
                    newj ^= (1 << (u[h] - 1));
                }
                if ((!(i >> (v[h] - 1) & 1)) || (j >> (v[h] - 1) & 1)) {
                    newj ^= (1 << (v[h] - 1));
                }
                dp[newi][newj] += dp[i][j];
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int z = __builtin_popcount(i);
        if (z == k) {
            ans += dp[(1 << n) - 1][i];
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