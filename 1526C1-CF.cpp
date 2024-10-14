//problem "1526C1-CF"
//created in 16:46:38 - Fri 11/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, a[N];
long long dp[N][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1e15;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > 0 && dp[i - 1][j - 1] + a[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[n][i] >= 0) {
            ans = i;
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