//problem "150-marisa"
//created in 08:52:03 - Sun 03/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int dp[N][N], m, n;

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= min(m, n); i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[m][n];
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