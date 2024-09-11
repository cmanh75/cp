//problem "213C-CF"
//created in 16:21:23 - Thu 05/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 305;
int n, a[N][N], dp[N * 2][N][N];

void Max(int i, int j, int k, int y) {
    int z = a[j][i - j];
    int u = a[k][i - k];
    dp[i][j][k] = max(dp[i][j][k], y + z + u * (j != k));
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n * 2; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[i][j][k] = -1e9;
            }
        }
    }
    dp[2][1][1] = a[1][1];
    for (int i = 2; i < n * 2; i++) {
        for (int j = 1; j <= min(i - 1, n); j++) {
            for (int k = 1; k <= min(i - 1, n); k++) {
                Max(i + 1, j, k, dp[i][j][k]);
                Max(i + 1, j + 1, k, dp[i][j][k]);
                Max(i + 1, j, k + 1, dp[i][j][k]);
                Max(i + 1, j + 1, k + 1, dp[i][j][k]);
            }
        }
    }
    cout << dp[2 * n][n][n];
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