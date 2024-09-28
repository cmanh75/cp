//problem "volimpic"
//created in 11:58:02 - Wed 18/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N], n, k;
long long dp[N][65600], pre[N][65600];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }
    }       
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << k); j++) {
            for (int h = 0; h < k; h++) {
                dp[i][j] += (j >> h & 1) * a[i][h + 1];
            }
        }
    }
    long long ans = 0;
    for (int h = 2; h <= 3; h++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << k); j++) {
                pre[i][j] = dp[i][j];
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << k); j++) {
                pre[i][j] = max(pre[i][j], pre[i - 1][j]);
                dp[i][j] = max(pre[i][j], dp[i][j]);
                for (int r = 0; r < k; r++) {
                    if (j >> r & 1) {
                        dp[i][j] = max(dp[i][j], dp[i][j ^ (1 << r)] + a[i][r + 1]);
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
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