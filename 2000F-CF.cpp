//problem "2000F-CF"
//created in 16:33:55 - Sat 24/08/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, w, a[N], b[N], f[N][N], dp[N][N];

void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        for (int k = 1; k <= a[i] + b[i]; k++) {
            f[i][k] = 1e9;
            for (int h = 0; h <= min(b[i], k); h++) {
                if (k - h > a[i]) {
                    continue;
                }
                f[i][k] = min(f[i][k], h * a[i] + (b[i] - h) * (k - h));
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            for (int z = 0; z <= min(j, a[i] + b[i]); z++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - z] + f[i][z]);
            }
        }
    }
    if (dp[n][w] == 1e9) {
        cout << -1 << "\n";
        return;
    }
    cout << dp[n][w] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}