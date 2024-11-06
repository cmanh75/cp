//problem "159-marisa"
//created in 15:21:04 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int n, k, dp[N][N], a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] + 1ll * dp[i - 1][j - 1] * a[i]) % mod;
        }
    }
    cout << dp[n][k];
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